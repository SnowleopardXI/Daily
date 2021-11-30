#include <stdio.h>
#include <math.h>

double funcos( double e, double x )
{
    double item=1,cosx=1,fenzi=1,fenmu=1;
    int flag,i;
    flag=-1;
    for(i=2;fabs(item)>=e;i+=2)
    {
        fenmu*=(i*(i-1));
        fenzi*=(x*x);
        item=1.0*flag*fenzi/fenmu;
        cosx+=item;
        flag*=-1;
    }
    return cosx;
}

int main()
{    
    double e, x;
    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));
    return 0;
}