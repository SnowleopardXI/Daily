#include<stdio.h>
int main()
{
    const long int n=100000000;
    int m,i,j;
    scanf("%d",&m);
    for (i=0,j=0;i<n;i++)
    {
        if(j==m)
        {
            return 0;
        }
        if(i%3==2&&i%5==3&&i%7==5)
        {
            printf("%d\t",i);
            j++;
        }
    }
    return 0;
}