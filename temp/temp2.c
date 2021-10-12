#include <stdio.h>
int main()
{
    double a,b;
    scanf("%lf%lf",&a,&b);
    char C='%';
    printf("%lfC%lf=%lf",a,C,b,a%b);
    return 0;
}