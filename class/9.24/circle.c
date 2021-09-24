#include <stdio.h>
#include <math.h>
#define PI 3.1416
int main(void)
{
    int radius;
    double area,perimeter;
    scanf("%d",&radius);
    area=PI*pow(radius,2);
    perimeter=2*PI*radius;
    printf("Perimeter is:%7.3lf\nArea is:%7.3lf",perimeter,area);
    return 0;
}
