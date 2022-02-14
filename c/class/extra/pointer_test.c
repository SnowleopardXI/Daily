#include <stdio.h>
int main()
{
    int i,*p,array[3];
    p=array;
    printf("%p\n",p);
    for ( i = 0; i < 3; i++)
    {
        scanf("%d",*p++);
        p++;
    }
    printf("%p\n",p);
    p=array;
    for (i = 0; i < 3; i++)
    {
        printf("%p ",p++);
    }
    return 0;
}