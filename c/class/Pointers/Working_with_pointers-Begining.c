#include <stdio.h>
int main()
{
    int a;
    int *p;
    a=10;
    p=&a;// &a : address of a
    printf("Address of p is %p\n",p);
    printf("Value at p is %d\n",*p);
    int b=20;
    *p=b;//Value of pointer p changed to b
    printf("Address of p is %p\n",p);
    printf("Value at p is %d\n",*p);
}