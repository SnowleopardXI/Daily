#include <stdio.h>
void swap(int *a,int *b)
{
    int *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int a=2,b=8,*pa,*pb;
    pa=&a,pb=&b;
    printf("Address of a is :%p\tAddress of b is :%p\na=%d,b=%d\n",pa,pb,a,b);
    swap(pa,pb);
    printf("Address of a is :%p\tAddress of b is :%p\na=%d,b=%d\n",pa,pb,a,b);
}