#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100
#define MESSAGE "Hello from child process!"

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // 子进程
        close(pipefd[0]);  // 关闭读端
        while (1) {
            write(pipefd[1], MESSAGE, strlen(MESSAGE) + 1);  // 发送消息
            sleep(3);  // 每隔3秒发送一次
        }
        close(pipefd[1]);  // 关闭写端
        exit(EXIT_SUCCESS);
    } else {  // 父进程
        close(pipefd[1]);  // 关闭写端
        while (1) {
            ssize_t count = read(pipefd[0], buffer, BUFFER_SIZE);
            if (count == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            } else if (count == 0) {
                break;  // 管道中无数据可读
            } else {
                printf("父进程收到: %s\n", buffer);  // 打印收到的消息
            }
        }
        close(pipefd[0]);  // 关闭读端
        wait(NULL);  // 等待子进程结束
        exit(EXIT_SUCCESS);
    }
}
