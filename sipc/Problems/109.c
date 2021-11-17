#include <stdio.h>
int main()
{
    int a,b,i=1;
    scanf("%d %d",&a,&b);
    if (a>b)
        return 0;
    while (b-a>0)
    {
        a=a*2;
        i++;
    }
    printf("%d\n",i);
    return 0;
}