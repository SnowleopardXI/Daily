#include <stdio.h>
long long int jiecheng(int n)
{
    long long int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
int main()
{
    int i;
    long long int sum=0,temp=0;
    for (i = 1; i <= 20; i++)
        sum+=jiecheng(i);
    printf("%lld\n",sum);
    return 0;
}