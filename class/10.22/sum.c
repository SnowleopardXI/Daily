#include <stdio.h>
int main()
{
    int n=0,sum=0;
    do
    {
        scanf("%d",&n);
        sum+=n;
    } while (n!=0);
    printf("%d",sum);
    return 0;
}