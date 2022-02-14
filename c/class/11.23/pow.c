#include <stdio.h>
double calc_pow(double x, int n)
{
    if(n==0)
    {
        return 1;
    }
    else if (n==1)
    {
        return x;
    }
    else return x*calc_pow(x,n-1);
}
int main()
{
    double x;
    int n;
    scanf("%lf %d",&x,&n);
    printf("%f\n", calc_pow(x, n));
    return 0;
}