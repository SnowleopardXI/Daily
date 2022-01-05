#include "stdio.h"
int min(int a[],int n)
{
    int min=a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i]<=min)
        min=a[i];
    }
    return min;
}
int main()
{
    int array[10],pos=0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",&array[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if(array[i]!=min(array,10))
        {
            pos++;
        }
        
    }
    printf("%d\n",pos);
    int temp=array[0];
    array[0]=min(array,10);
    array[pos+1]=temp;
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",array[i]);
    }
}