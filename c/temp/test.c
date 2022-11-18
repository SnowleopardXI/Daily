#include <stdio.h>
int main()
{
    double p, y, x;
    printf("please enter x:");
    scanf("%lf", &x);
    if (x <= 1600)
        p = 0;
    else if (x > 1600 && x <= 2500)
        p = 0.05;
    else if (x > 2500 && x <= 3500)
        p = 0.1;
    else if (x > 3500 && x <= 4500)
        p = 0.15;
    else if (4500 < x)
        p = 0.2;
    y = p * (x - 1600);
    printf("y=%lf\n", y);
    return 0;
}