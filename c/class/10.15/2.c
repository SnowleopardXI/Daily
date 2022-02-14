#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d",&a,&b);
    a=(a>b)?b:a;
    b=(a>b)?b:a;
    printf("%d %d\n",a,b);
    return 0;
}