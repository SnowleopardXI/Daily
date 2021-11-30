#include <stdio.h>
int main()
{
    int a=10;
    int *p;
    p=&a;
    printf("Address p is %p\n",p);
    printf("Value at address p is %d\n",*p);
    printf("Size of integer is %d bytes\n",sizeof(int));
    printf("Address p+1 is %p\n",p+1);//pointer address+4times
    printf("Value at address p is %d\n",*(p+1));
}