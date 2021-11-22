#include <stdio.h>
int main()
{
    char a ='F';
    int f=123;
    char *pa=&a;
    int *pb=&f;
    printf("a=%c\tf=%d\n",*pa,*pb);
    *pa = 'C';
    *pb+=1;
    printf("a=%c\tf=%d\n",*pa,*pb);
    printf("*pa= %p, *pb= %p",*pa,*pb);
    return 0;
}