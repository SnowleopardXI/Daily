#include <stdio.h>
int main()
{
    int n,i=1;
    scanf("%d",&n);
    while (i<n)
    {
        i*=2;
    }
    printf("%d",i);
    return 0;
}