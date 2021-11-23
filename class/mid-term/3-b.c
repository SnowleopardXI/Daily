#include <stdio.h>
#include <math.h>
int main()
{
    int sum,a,b,c,d;
    for (sum = 1000; sum < 10000; sum++)
    {
        a=sum/1000;
        b=sum%1000/100;
        c=sum%100/10;
        d=sum%10;
        if (pow(a,4)+pow(b,4)+pow(c,4)+pow(d,4)==sum)
        printf("%d\t",sum);
    }
    return 0;
}