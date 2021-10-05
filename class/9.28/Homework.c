#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    int x,y,plus,minus,multiply;
    double divide;
    printf("Please input two numbers:");
    scanf("%d %d",&x,&y);
    plus=x+y;
    minus=x-y;
    multiply=x*y;
    divide=(double)x/y;
    printf("%d+%d=%d\n",x,y,plus);
    printf("%d-%d=%d\n",x,y,minus);
    printf("%d*%d=%d\n",x,y,multiply);
    printf("%d/%d=%.2f\n",x,y,divide);
    return 0;
}