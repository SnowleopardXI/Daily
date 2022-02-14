#include<stdio.h>
int main()
{
    long long i,n,sum=0,mul=1;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        mul*=i;
        sum+=mul;
    }
    printf("%lld",sum);
    return 0;
}