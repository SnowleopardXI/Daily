#include <stdio.h>
#include <math.h>
int main()
{
    float x1, y1, x2, y2;
    while (~scanf("%f %f %f %f\n", &x1, &y1, &x2, &y2))
    {
        printf("%.2f\n", sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)));
    }
    return 0;
}