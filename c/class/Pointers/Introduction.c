#include <stdio.h>
int main()
{
    int a;
    int *p;
    p=&a;
    a=5;
    printf("p=%p ,&a=%d",*p,a);
    return 0;
}