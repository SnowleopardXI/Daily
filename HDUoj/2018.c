#include <stdio.h>
int summon(int x)
{
    int o,p;
    if(x<=4)
    return 2;
    else
        return (summon(x-4)+2);
}
int main()
{
    int i,j,n;
    scanf("%d",&n);
    if (n==0)
    return 0;
    printf("%d\n",summon(n));
    return 0;
}