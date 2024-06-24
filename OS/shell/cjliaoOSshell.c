#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 100
#define HISTORY_SIZE 100

char *history[HISTORY_SIZE];
int history_count = 0;

void parseInput(char *input, char **args, int *background) {
    for (int i = 0; i < MAX_ARGS; i++) {
        args[i] = strsep(&input, " \t\r\n\a");
        if (args[i] == NULL) break;
    }
    if (args[0] == NULL) return;

    // Check if last argument is '&'
    if (args[0] != NULL && strcmp(args[0], "&") == 0) {
        *background = 1;
        args[0] = NULL;
    } else {
        *background = 0;
    }
}

void executeCommand(char **args, int background) {
    pid_t pid;
    int status;

    // Construct command path for custom commands
    char command_path[1024];
    snprintf(command_path, sizeof(command_path), "./%s", args[0]);

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execvp(command_path, args) == -1) {
            perror("cjliaoOSshell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("cjliaoOSshell");
    } else {
        // Parent process
        if (!background) {
            do {
                waitpid(pid, &status, WUNTRACED);
            } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        } else {
            printf("Process running in background with PID: %d\n", pid);
        }
    }
}

void add_history(char *input) {
    if (history_count < HISTORY_SIZE) {
        history[history_count] = strdup(input);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 1; i < HISTORY_SIZE; i++) {
            history[i - 1] = history[i];
        }
        history[HISTORY_SIZE - 1] = strdup(input);
    }

    // Save history to file
    FILE *file = fopen("history", "a");
    if (file != NULL) {
        fprintf(file, "%s", input);
        fclose(file);
    }
}

void show_history() {
    int start = history_count > 10 ? history_count - 10 : 0;
    for (int i = start; i < history_count; i++) {
        printf("%d %s", i + 1, history[i]);
    }
}

void handle_special_commands(char *input, char **args) {
    if (strcmp(input, "history\n") == 0) {
        show_history();
    } else if (strcmp(input, "!!\n") == 0) {
        if (history_count == 0) {
            printf("No commands in history.\n");
        } else {
            printf("%s", history[history_count - 1]);
            parseInput(history[history_count - 1], args, 0);
            executeCommand(args, 0);
        }
    } else if (input[0] == '!' && input[1] != '\0' && isdigit(input[1])) {
        int command_number = atoi(&input[1]);
        if (command_number <= 0 || command_number > history_count) {
            printf("No such command in history.\n");
        } else {
            printf("%s", history[command_number - 1]);
            parseInput(history[command_number - 1], args, 0);
            executeCommand(args, 0);
        }
    } else if (strcmp(input, "clear\n") == 0) {
        printf("\033[H\033[J");  // ANSI escape code to clear screen
    }
}

int main() {
    char *input = NULL;
    char *args[MAX_ARGS];
    size_t bufsize = 0;
    int background;

    while (1) {
        printf("cjliaoOSshell> ");
        getline(&input, &bufsize, stdin);

        // Check for exit command
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        // Add to history
        add_history(input);

        parseInput(input, args, &background);

        if (args[0] != NULL) {
            // Handle special commands
            handle_special_commands(input, args);
            // Execute the command if not a special command
            executeCommand(args, background);
        }
    }

    free(input);
    return 0;
}
