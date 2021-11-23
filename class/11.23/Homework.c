#include <stdio.h>
#include <math.h>
double funcos(double e, double x)
{
    double result=0,tmp=1,fact=1;
    int power=0,sgn=1;
    while (tmp >= e)
    {
        tmp=pow(x,power)/fact;
        result+=tmp*sgn;
        power+=2;
        fact*=(power)*(power-1);
        sgn*=-1;
    }
    return result;
}
int main()
{
    int i,j;
    double e,x;
    scanf("%lf %lf",&e,&x);
    printf("cos(%.2f) = %.6f\n",x,funcos(e,x));
    return 0;
}