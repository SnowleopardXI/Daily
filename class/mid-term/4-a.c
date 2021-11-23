#include <stdio.h>
#include <math.h>
int main()
{
    int i=1;
    double x,sum,temp=1;
    scanf("%lf",&x);
    sum=x;
    while (fabs(temp)> 0.000001)
    {
        if (i%2!=0)
            temp=-(pow(x,2*i+1))/(2*i+1);
        else
            temp=(pow(x,2*i+1))/(2*i+1);
        sum+=temp;
        i++;
    }
    printf("%lf",sum);
    return 0;
}