#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096  // 定义缓冲区大小

void cat(const char *filename) {
    int fd;
    char buffer[BUFFER_SIZE];
    ssize_t nread;

    fd = open(filename, O_RDONLY); // 打开文件只读
    if (fd == -1) {
        perror("Failed to open file");
        return;
    }

    while ((nread = read(fd, buffer, BUFFER_SIZE)) > 0) {
        // 读取文件内容到缓冲区，并检查读取的字节数
        if (write(STDOUT_FILENO, buffer, nread) != nread) {
            // 将缓冲区内容写到标准输出，并检查写入的字节数
            perror("Failed to write to stdout");
            close(fd);
            return;
        }
    }

    if (nread == -1) {
        perror("Failed to read file");
    }

    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2 ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        cat(argv[i]); // 对每个命令行参数调用 cat 函数
    }

    return EXIT_SUCCESS;
}
