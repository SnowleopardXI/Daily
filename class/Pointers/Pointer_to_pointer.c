#include <stdio.h>
int main()
{
    int x=5;
    int *p=&x;
    *p=6;
    int **q=&p;
    int ***r=&q;
    printf("%d\n",*p);
    printf("%p\n",*q);
    printf("%d\n",**q);
    printf("%p\n",**r);
    printf("%d\n",***r);
    ***r=10;
    printf("x= %d\n",x);
    **q=*p+2;
    printf("x= %d\n",x);
    return 0;
}