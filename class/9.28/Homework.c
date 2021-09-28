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
    printf("x+y=%d\n",plus);
    printf("x-y=%d\n",minus);
    printf("x*y=%d\n",multiply);
    printf("x/y=%.2f\n",divide);
    return 0;
}