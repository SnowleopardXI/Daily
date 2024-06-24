#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) //将自变量传递到函式
{
    int fdSrc;            //用来放原始档source file的档案描述符 source originalurce
    int fdDes;            //用来放目标档案object file的档案描述符 destination target
    char* Buf = NULL;     //用来存放读出来的字符串

        printf("cjliao: My copy file function\n");
        if(argc != 3){        //用来判断是否输入了3个自变量
        printf("error\n");
        exit(-1);         //强制退出
    }

    fdSrc = open(argv[1], O_RDWR);
        //开启原始档 original_file

        int size = lseek(fdSrc, 0, SEEK_END);
        //计算原始文件original_file的大小（字节数）

        lseek(fdSrc, 0, SEEK_SET);
        //将游标重新定位到档案file的头

        Buf = (char *)malloc(sizeof(char) * size);
        //为char型的buf指标pointer开辟配置空间，大小为一个char的大小 X 档案file的大小(字节数)
    //malloc: memory allocation

        int n_read = read(fdSrc, Buf, size);
        //将开启的原始档original_file读到缓冲区buf中，大小为档案file的大小

        fdDes = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0600);
        //开启目标file，如果没有的话就要建立目标file，
        //file权限为可读可写，并且清除目标file的原内容。

        int n_write = write(fdDes, Buf, size);
        //将缓冲区buf中的数据写到目标file中，
        //大小为读出原始档original_file的file大小。

        close(fdSrc);
        //要将原始文件和目标file都要关闭
    close(fdDes);

        return 0;
}
