#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i,a[10];
    srand(time(0));
    for (i = 0; i < 10; i++)
    {
        a[i]=rand()%26;
    }
    for (i = 0; i < 10; i++)
    {
        printf("Element at memory %p is %d\n",a[i],a[i]);
    }
    return 0;
}