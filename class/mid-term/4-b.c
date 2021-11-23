#include <stdio.h>
double calc_pow(double x, int n)
{
    if(n==0){return 1;}
    else if (n==1){return x;}
    else return x*calc_pow(x,n-1);
}
int jc(int x)
{
    int sum=x;
    if (x>1)
    return sum*jc(x-1);
}
int main()
{
    int i=1;
    double sumx,sumi,x,result=1;
    scanf("%lf",&x);
    while (calc_pow(x,i)/jc(i)>0.0001)
    {
        result+=(calc_pow(x,i)/jc(i));
        i++;
    }
    printf("%lf",result);
    return 0;
}