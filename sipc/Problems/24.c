#include<stdio.h>
int main()
{
    int m, n, temp, i;
    scanf("%d%d", &m, &n);
    if(m<n) 
    {
        temp=m;
        m=n;
        n=temp;
    }
    for(i=n; i>0; i--) 
        if(m%i==0 && n%i==0)
        {
            printf("%d ", i);
            break;
        }
    for (i ; i <2e30 ; i++)
    {
        if (i%m==0&&i%n==0)
        {
            printf("%d",i);
            break;
        }
    }
    return 0;
}