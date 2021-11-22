#include <stdio.h>
int main()
{
    int i;
    float sum=0,temp,tempa,a=2,b=1;
    for (i = 0; i < 20; i++)
    {
        temp=a/b;
        sum+=temp;
        tempa=a;
        a+=b;
        b=tempa;
    }
    printf("%lf",sum);
    return 0;
}