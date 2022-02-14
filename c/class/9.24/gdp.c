#include <stdio.h>
#include <math.h>
int main()
{
    int year;
    double out,formula;
    scanf("%d",&year);
    formula=pow((1+0.07),year);
    printf("%.2lf",formula);
    return 0;
}
