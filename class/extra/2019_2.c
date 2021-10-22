#include<stdio.h>
int main()
{
    int m,i,j;
    scanf("%d",&m);
    for (i = 1; i < m; i++)
    {
        for (j = 1; j < m ;j++)
        {
            if (m%j==0)
            {
                printf("%d is not qualified.\n",m);
            }
        }
        
    printf("%d",m);
    }
    return 0;
}