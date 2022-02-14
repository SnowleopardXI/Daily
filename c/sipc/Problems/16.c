#include <stdio.h>
#include <math.h>
void main()
{
    int n,sum=0,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    sum=sum+pow(2.0,i);
    printf("%d",sum);
}