#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>
#include <signal.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100
#define HISTORY_SIZE 100

char *history[HISTORY_SIZE];
int history_count = 0;
int flag = 0;

void add_to_history(char *input)
{
    // 添加到内存的历史数组
    if (history_count < HISTORY_SIZE)
    {
        history[history_count++] = strdup(input);
    }
    else
    {
        // 当历史记录已满时，删除最旧的命令
        free(history[0]);
        memmove(history, history + 1, sizeof(char *) * (HISTORY_SIZE - 1));
        history[HISTORY_SIZE - 1] = strdup(input);
    }
    // 同时将命令追加到文件
    FILE *file = fopen("history", "a");
    if (file)
    {
        fprintf(file, "%s", input); // 确保写入的是完整命令
        fclose(file);
    }
}

void parseInput(char *input, char **args, int *background)
{
    int i;
    for (i = 0; i < MAX_ARGS; i++)
    {
        args[i] = strsep(&input, " \t\r\n\a");
        if (args[i] == NULL)
            break;
        if (strlen(args[i]) == 0)
            i--; // Skip empty strings
    }
    *background = 0;
    if (i > 0 && strcmp(args[i - 1], "&") == 0)
    {
        *background = 1;
        args[i - 1] = NULL;
    }
}

void executeCommand(char **args, int background)
{
    if (flag == 1)
    {
        flag = 0;
        return;
    }
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return;

    if (strcmp(args[0], "cd") == 0)
    {
        char *path = args[1] ? args[1] : getenv("HOME");
        if (chdir(path) != 0)
        {
            perror("cjliaoOSshell");
        }
        return;
    }

    char cmd[1024];
    char *cwd = getcwd(NULL, 0);
    snprintf(cmd, sizeof(cmd), "%s/%s", cwd, args[0]);

    pid = fork();
    if (pid == 0)
    {
        signal(SIGINT, SIG_DFL);

        if (access(cmd, X_OK) == 0)
        {
            execv(cmd, args);
        }
        else
        {
            execvp(args[0], args);
        }
        perror("cjliaoOSshell");
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("cjliaoOSshell");
    }
    else
    {
        if (!background)
        {
            do
            {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
        else
        {
            printf("Process running in background with PID: %d\n", pid);
        }
    }
}

void show_history()
{
    flag = 1;
    int start = history_count > 10 ? history_count - 10 : 0;
    for (int i = start; i < history_count; i++)
    {
        printf("%d %s", i + 1, history[i]);
    }
}

int handle_special_commands(char *input, char **args, int *background)
{
    char *tmp = strdup(input);
    if (strcmp(input, "clear\n") == 0 || strcmp(input, "\f") == 0)
    {
        printf("\033[H\033[J");
        free(tmp);
        return 1; // 表示已处理
    }
    if (strcmp(input, "!!") == 0)
    {
        if (history_count == 0)
        {
            printf("No commands in history.\n");
        }
        else
        {
            // 执行最近的一条命令
            printf("%s", history[history_count - 2]);
            strcpy(input, history[history_count - 2]);
            parseInput(input, args, background);
            *background = 0;
            executeCommand(args, *background);
            free(tmp);
            return 1; // 表示已处理
        }
    }
    if (input[0] == '!')
    {
        int n = atoi(input + 1);
        if (n < 1 || n > history_count)
        {
            printf("Command %s, No such command in history.\n", input);
        }
        else
        {
            strcpy(input, history[n - 1]);
            parseInput(input, args, background);
            *background = 0;
            executeCommand(args, *background);
        }
        free(tmp);
        return 1; // 表示已处理
    }
    if (strcmp(args[0], "history") == 0)
    {
        show_history();
        free(tmp);
        return 1; // 表示已处理
    }
    // 如果需要管道，将前方命令执行结果转为标准输入传递到后续命令
    if (strchr(input, '|') != NULL)
    {
        int fd[2];
        pipe(fd);
        pid_t pid = fork();
        if (pid == 0)
        {
            char *cmd1 = strsep(&tmp, "|");
            char *cmd2 = strsep(&tmp, "|");
            char *args1[MAX_ARGS];
            char *args2[MAX_ARGS];
            parseInput(cmd1, args1, background);
            parseInput(cmd2, args2, background);
            int fd1 = open("tmp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
            dup2(fd1, STDOUT_FILENO);
            executeCommand(args1, *background);
            close(fd1);
            exit(0);
        }
        wait(NULL);
        pid = fork();
        if (pid == 0)
        {
            char *cmd1 = strsep(&tmp, "|");
            char *cmd2 = strsep(&tmp, "|");
            char *args1[MAX_ARGS];
            char *args2[MAX_ARGS];
            parseInput(cmd1, args1, background);
            parseInput(cmd2, args2, background);
            int fd1 = open("tmp", O_RDONLY);
            dup2(fd1, STDIN_FILENO);
            executeCommand(args2, *background);
            close(fd1);
            exit(0);
        }
        wait(NULL);
        free(tmp);
        return 1; // 表示已处理
    }
    free(tmp);
    return 0; // 表示未处理
}

int main()
{
    char *input = NULL;
    char *args[MAX_ARGS];
    size_t bufsize = 0;
    int background = 0;

    signal(SIGINT, SIG_IGN);

    while (1)
    {
        printf("cjliaoOSshell> ");
        if (getline(&input, &bufsize, stdin) == -1)
        {
            if (feof(stdin))
            {
                printf("exit\n");
                break;
            }
            else
            {
                continue;
            }
        }

        if (input[0] == '\n')
            continue;

        if (strcmp(input, "exit\n") == 0)
        {
            printf("Exiting...\n");
            break;
        }

        add_to_history(input);
        parseInput(input, args, &background);

        if (args[0] == NULL)
            continue;

        if (handle_special_commands(input, args, &background))
        {
            continue;
        }

        executeCommand(args, background);
    }

    free(input);
    for (int i = 0; i < history_count; i++)
    {
        free(history[i]);
    }
    return 0;
}
