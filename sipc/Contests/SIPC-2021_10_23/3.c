#include <stdio.h>
#include <math.h>
int isPrime(int n)
{
    int j;
    for (j = 2; j <= (int)sqrt(n); j++)
    {
        if (n % j == 0)
        return 0;
    }
    return 1;
}
int main()
{
    int i,x,y,sum=0,temp;
    scanf("%d %d",&x,&y);
    for (i = x; i <= y; i++)
    {
        temp=(int)isPrime(i);
        sum=+temp;
        printf("%d",temp);
    }
    printf("%d",sum);
    return 0;
}