#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    int i;
    for (i = 2; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        return 0;
    }
    return 1;
}
int main()
{
    int i,x,y;
    scanf("%d %d",&x,&y);
    for (i = x; i <= y; i++)
    {
        if (isPrime(i))
        printf("%d ", i);
    }
    return 0;
}