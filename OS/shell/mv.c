#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
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

    // 获取源文件和目标目录的文件系统信息
    if (stat(argv[1], &statSrc) == -1 || stat(argv[2], &statDes) == -1) {
        perror("Error getting file information");
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
        char* Buf = NULL;
        int size = lseek(fdSrc = open(argv[1], O_RDONLY), 0, SEEK_END);
        lseek(fdSrc, 0, SEEK_SET);
        Buf = (char *)malloc(sizeof(char) * size);
        read(fdSrc, Buf, size);
        fdDes = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0600);
        write(fdDes, Buf, size);
        close(fdSrc);
        close(fdDes);
        free(Buf);

        // 删除原始文件
        if (unlink(argv[1]) == -1) {
            perror("Error deleting original file");
            exit(-1);
        }
    }

    return 0;
}
