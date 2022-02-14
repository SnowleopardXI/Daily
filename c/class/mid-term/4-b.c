#include <stdio.h>
#include <math.h>
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
    while (pow(x,i)/jc(i)>0.0001)
    {
        result+=(pow(x,i)/jc(i));
        i++;
    }
    printf("%lf",result);
    return 0;
}