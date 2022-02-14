#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[10],i,temp;
    srand(time(0));
    for (i = 0; i < 10; i++)
    {
        a[i]=rand()%21+5;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        temp=a[i];
        a[i]=a[9-i];
        a[9-i]=temp;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}