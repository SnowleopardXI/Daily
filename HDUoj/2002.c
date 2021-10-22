#include <stdio.h>
#include <math.h>
#define PI 3.1415927
int main()
{
    double r,out;
    while(scanf("%lf\n", &r)!=EOF) 
    {
        out=((double)4/3)*PI*pow(r,3);
        printf("%.3lf\n",out);
    }
    return 0;
}