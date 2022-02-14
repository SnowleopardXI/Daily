#include <stdio.h>
int main()
{
    int x;
    printf("请输入一个整数:");
    scanf("%d",&x);
    if(x%3==0&&x%5==0)
    printf("能同时被3，5整除");
    else {
        if(x%3==0&&x%5!=0)
        printf("能被3整除，不能被5整除");
        else if(x%3!=0&&x%5==0)
        printf("能被5整除，不能被3整除");
        else
        printf("不能被3，5任一个整除");
    }
}