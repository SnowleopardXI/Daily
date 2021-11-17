#include <stdio.h>
int main()
{
    int m=0,n=0,i,j;
    scanf("%d",&n);
    int a[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (i!=n-1&&j!=n-1&&j!=n-1-i)
                m+=a[i][j];
        }
    }
    printf("%d",m);
    return 0;
}