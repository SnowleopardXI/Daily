#include <stdio.h>
int is_prime(int x)
{
    int y;
    for (y = 2; y < x; y++)
    {
        if (x%y==0)
        return 0;
        else
        return 1;
    }
}
int main()
{
    int n,i,count=0;
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        is_prime(i);
        count=+is_prime(i);
    }
    printf("%d",count);
    return 0;
}