#include <stdio.h>

int main() {
    FILE *fptr; // 定义指向文件的指针
    char c, upper, lower;
    int i;
    
    // 打开文件
    fptr = fopen("output.txt", "w");
    
    //大小写交替写入
    for (i = 0; i < 26; i++) {
        upper = 'A' + i;
        lower = 'a' + i;
        fputc(upper, fptr);
        fputc(lower, fptr);
    }
    
    
    // 关闭文件
    fclose(fptr);
    
    return 0;
}
