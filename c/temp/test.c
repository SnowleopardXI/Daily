#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    float p,r;
    scanf("%d",&n);
    r=0.07;
    p=pow(1+r,n);
    printf("%f",p);
    return 0;
}
