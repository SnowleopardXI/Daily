#include <stdio.h>
int main()
{
    int n,a,i,min;
    while (~scanf("%d",&n))
    {
        int array[n-1];
        for (i = n-1; i >=0; i--)
        {
            scanf("%d",&a);
            array[i]=a;
        }
        min=array[0];
        for (i = 1; i <= n; i++)
        {
            if (array[i]<min)
            {
                min=array[i];
            }
        }
        
    }
    printf("%d",min);
}