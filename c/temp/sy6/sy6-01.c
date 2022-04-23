#include <stdio.h>
int factorial(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
        fact *= i;
    return fact;
}
int main()
{
    int m,n,k;
    long s;
    printf("Please input m,n,k: ");
    scanf("%d%d%d",&m,&n,&k);
    s=factorial(m)+factorial(n)+factorial(k);
    printf("s=%ld\n",s);
    return 0;
}