#include <stdio.h>
int main()
{
    int inp,n;
    printf("请输入大于0小于10000的整数");
    scanf("%d",&inp);
    if(inp<=0||inp>=10000)
        printf("输入错误");
    else if(inp<10)
        n=1;
        //printf("一位数");
            else if(inp<100)
                n=2;