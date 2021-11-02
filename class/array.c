#include <stdio.h>
int main()
{
    int i,array[10];
    for (i = 0; i < 10; i++)
    {
        array[i]=i;
    }
    for ( i = 9; i >=0; i--)
    {
        printf("%d ",array[i]);
    }
    return 0;
}