#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define FILENAME "/tmp/test.txt"
#define BUFFER_SIZE 1024

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    // 创建或打开文件
    fd = open(FILENAME, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("打开文件失败");
        exit(EXIT_FAILURE);
    }

    // 获取用户输入
    printf("请输入要保存到文件的字符串: ");
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        perror("读取输入失败");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 写入文件
    bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1) {
        perror("写入文件失败");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 关闭文件
    close(fd);

    // 重新打开文件用于读取
    fd = open(FILENAME, O_RDONLY);
    if (fd == -1) {
        perror("打开文件失败");
        exit(EXIT_FAILURE);
    }

    // 读取文件内容
    printf("文件内容如下:\n");
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(STDOUT_FILENO, buffer, bytes_read) != bytes_read) {
            perror("输出到屏幕失败");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("读取文件失败");
    }

    // 关闭文件
    close(fd);

    return 0;
}
