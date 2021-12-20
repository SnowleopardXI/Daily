#include <stdio.h>
#include <math.h>
float x1, x2, a, b, c, delta;
void deltaZero(float a, float b, float c)
{
    x1 = -b / (2 * a);
}
void deltaLargerZero(float a, float b, float c, float delta)
{
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
}
void deltaLessZero(float a, float b, float c, float delta)
{
    x1 = -b / (2 * a);
    x2 = x1;
}
int main()
{
    printf("Please input a, b, c :");
    scanf("%f%f%f", &a, &b, &c);
    delta = pow(b, 2) - (4 * a * c);
    if (a)
    {
        if (delta == 0)
        {
            deltaZero(a, b, c);
            printf("X1=X2=%f", x1);
        }
        else
        {
            if (delta > 0)
            {
                deltaLargerZero(a, b, c, delta);
                printf("X1=%f,X2=%f", x1, x2);
            }
            else
            {
                deltaLessZero(a, b, c, delta);
                delta = -delta;
                printf("X1=%f-%fi,X2=%f+%fi", x1, sqrt(delta) / (2 * a), x2, sqrt(delta) / (2 * a));
            }
        }
    }
    else
        printf("X=%f", -b / c);
}
