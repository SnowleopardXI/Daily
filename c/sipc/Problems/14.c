#include <stdio.h>
int val(int x)
{
    float out;
    if (x%2==0)
    out=-(float)x/(x*2-1);
    else
    out=(float)x/(x*2-1);
    return out;
}
int main()
{
    int i,n;
    float sum=0;
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        sum+=val(i);
    }
    printf("%.3f",sum);
    return 0;
}