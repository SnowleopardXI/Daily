#include <stdio.h>
#include <math.h>
int main()
{
    double s,area;
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    s=(a+b+c)/2.0;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("a=%d\tb=%d\tc=%d\n",a,b,c);
    printf("area is %.2lf\n",area);
    return 0;
}
