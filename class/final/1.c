#include <stdio.h>
double pow(double x,int n)
{
    int i;
    double result=1;
    for (i=0; i < n-1; i++)
        result*=x;
    return result;
}
double abs(double x)
{
    if (x>0)
    return x;
    return -x;
}
int main()
{
    int i=1,flag=-1;
    double x,result=0,middle;
    scanf("%lf",&x);
    middle=x;
    while (abs(middle)>1e-6)
    {
        result+=middle;
        middle=flag*pow(x,2*i+1)/(2*i+1);
        i++;
    }
    printf("%lf",result);
    return 0;
}