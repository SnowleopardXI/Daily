#include<stdio.h>
void main()
{
    int a=9;
    printf("%d\n",a);
    a+=a-=a+a;
    printf("%d\n",a); 
}