#include <stdio.h>
int main()
{
    int x,a,b,judge;
    scanf("%d",&x);
    a=x%3,b=x%5;
    if(a==0&&b==0)
    printf("能同时被3，5整除");
    else {
        if(a==0&&b!=0)
        printf("能被3整除，不能被5整除");
        else if(a!=0&&b==0)
        printf("能被5整除，不能被3整除");
        else
        printf("不能被3，5任一个整除");
    }
}