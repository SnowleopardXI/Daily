#include <stdio.h>
int main()
{
    int n,i,mid,min=2e31-1;
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&mid);
        if (mid<min)
        min=mid;
    }
    printf("%d",min);
    return 0;
}