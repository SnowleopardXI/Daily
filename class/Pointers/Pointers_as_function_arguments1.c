#include <stdio.h>
void add(int *p)
{
    *p=(*p)+1;
}
int main()
{
    int a=10;
    add(&a);
    printf("a = %d",a);
    return 0;
}