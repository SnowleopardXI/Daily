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

    if (strcmp(args[0], "vi") == 0 && args[1] == NULL)
    {
        args[1] = "./cjliaoOSshell.c";
        args[2] = NULL; // 确保参数列表结束
    }

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
    int start = history_count > 10 ? history_count - 10 : 0;
    for (int i = start; i < history_count; i++)
    {
        dprintf(STDOUT_FILENO, "%d %s", i + 1, history[i]); // 使用 dprintf 直接向 STDOUT 写入
    }
}

int handle_special_commands(char *input, char **args, int *background)
{
    char *tmp = strdup(input);
    // 如果需要管道，将前方命令执行结果转为标准输入传递到后续命令
    if (strchr(input, '|') != NULL)
    {
        int fd[2], fd_in = 0;
        char *command = strtok(input, "|");

        while (command != NULL)
        {
            pipe(fd);
            pid_t pid = fork();
            if (pid == 0)
            {
                dup2(fd_in, 0);
                if (strtok(NULL, "|") != NULL)
                {
                    dup2(fd[1], 1);
                }
                close(fd[0]);

                char *local_args[MAX_ARGS];
                int local_background = 0;
                parseInput(command, local_args, &local_background);
                execvp(local_args[0], local_args);
                exit(EXIT_FAILURE);
            }
            else if (pid < 0)
            {
                perror("Failed to fork");
                return 1; // 处理错误
            }

            wait(NULL);    // 等待子进程结束
            close(fd[1]);  // 关闭写端
            fd_in = fd[0]; // 将读端保存，以供下一个命令使用

            command = strtok(NULL, "|");
        }
        if (fd_in != 0)
            close(fd_in);

        free(tmp);
        return 1; // 表示已处理
    }
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