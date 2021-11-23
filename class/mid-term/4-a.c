#include <stdio.h>
#include <math.h>
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
    int i,j;
    double x,s,sum;
    scanf("%lf",&x);
    sum=x;
    for ( i = 0; fabs((calc_pow(x,2n-1))/(2*n+1))> 0.000001; i++)
    {
        
        sum+=
    }
    
}