#include <stdio.h>
int max(int a,int b)
{
    if (a<b)
    return b;
    else return a;
}
int main()
{
    int x,y,i,j,k,maxi;
    scanf("%d",&x);
    int array1[x];
    for (i = 0; i < x; i++)
    {
        scanf("%d",&array1[i]);
    }
    scanf("%d",&y);
    int array2[y];
    for (i = 0; i < y; i++)
    {
        scanf("%d",&array2[i]);
    }
    maxi=max(x,y);
    int result[maxi];
    for (i = 0,k=0; i < x; i++)
    {
        for (j = 0; j<y ; j++)
        {
            if (array1[i]==array2[j])
            {
                result[k]=array1[i];
                k++;
                break;
            }
        }
        for ( i = 0; i <= k; i++)
        {
            printf("%d ",result[k]);
        }
    }
    return 0;
}