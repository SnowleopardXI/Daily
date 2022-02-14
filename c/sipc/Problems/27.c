#include <stdio.h>
int main()
{
    int i;
    double pi=1,midd=(double)1/3,sum,eps;
    scanf("PI = %le",&eps);
    for (i=1; midd>=eps ;i++)
    {
        midd=(i*midd)/(3*(2*i+1));
        pi+=midd;
    }
    pi*=2;
    printf("%lf",pi);
    return 0;
}