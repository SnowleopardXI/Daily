#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fdSrc, fdDes;      // 源文件和目标文件的文件描述符
    struct stat statSrc, statDes; // 用于存储文件状态信息

    printf("cjliao: My move file function\n");
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        exit(-1);
    }

    // 获取源文件的文件系统信息
    if (stat(argv[1], &statSrc) == -1) {
        perror("Error getting source file information");
        exit(-1);
    }

    // 获取目标目录的文件系统信息
    if (stat(argv[2], &statDes) == -1 && errno != ENOENT) {
        perror("Error getting destination file information");
        exit(-1);
    }

    // 检查是否在同一文件系统上
    if (statSrc.st_dev == statDes.st_dev) {
        // 如果在同一文件系统上，使用 rename 函数移动文件
        if (rename(argv[1], argv[2]) == -1) {
            perror("Error moving file");
            exit(-1);
        }
    } else {
        // 如果不在同一文件系统上，需要手动复制和删除
        fdSrc = open(argv[1], O_RDONLY);
        if (fdSrc == -1) {
            perror("Error opening source file");
            exit(-1);
        }

        int size = lseek(fdSrc, 0, SEEK_END);
        if (size == -1) {
            perror("Error getting size of source file");
            close(fdSrc);
            exit(-1);
        }
        lseek(fdSrc, 0, SEEK_SET);

        char* Buf = (char *)malloc(sizeof(char) * size);
        if (Buf == NULL) {
            perror("Error allocating memory");
            close(fdSrc);
            exit(-1);
        }

        if (read(fdSrc, Buf, size) != size) {
            perror("Error reading source file");
            free(Buf);
            close(fdSrc);
            exit(-1);
        }

        fdDes = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0600);
        if (fdDes == -1) {
            perror("Error opening/creating destination file");
            free(Buf);
            close(fdSrc);
            exit(-1);
        }

        if (write(fdDes, Buf, size) != size) {
            perror("Error writing to destination file");
            free(Buf);
            close(fdSrc);
            close(fdDes);
            exit(-1);
        }

        close(fdSrc);
        close(fdDes);
        free(Buf);

        // 删除原始文件
        if (unlink(argv[1]) == -1) {
            perror("Error deleting original file");
            exit(-1);
        }
    }

    printf("File moved successfully from '%s' to '%s'\n", argv[1], argv[2]);
    return 0;
}
