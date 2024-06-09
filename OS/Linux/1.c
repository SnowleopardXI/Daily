#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // fork() 失败
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // 子进程
        printf("子进程暂停5秒钟。\n");
        sleep(5);  // 子进程暂停5秒钟
        printf("子进程退出。\n");
        return 0;  // 子进程退出
    } else {
        // 父进程
        int status;
        printf("父进程调用 waitpid() 并暂停5秒钟。\n");
        sleep(5);  // 父进程暂停5秒钟
        
        pid_t ret = waitpid(pid, &status, 0);
        if (ret < 0) {
            // waitpid() 失败
            perror("Waitpid failed");
            return 1;
        } else if (WIFEXITED(status)) {
            // 子进程正常退出
            printf("捕获子进程退出，子进程号: %d\n", ret);
            printf("子进程退出状态: %d\n", WEXITSTATUS(status));
        } else {
            printf("子进程未正常退出。\n");
        }
    }

    return 0;
}
