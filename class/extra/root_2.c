#include <stdio.h>
void deltaZero(float a, float b, float c);
void deltaLargerZero(float a, float b, float c);
void deltaLessZero(float a, float b, float c);
float p, q, m, n, d;
int main()
{
    int a, b, c;
    d = b * b - 4 * a * c;
    m = -(c / b);
    printf("请输入a，b，c：");
    scanf("%d%d%d", &a, &b, &c);
    if (a != 0)
    {
        if (d > 0)
        {
            deltaLargerZero(a, b, c);
            printf("x1=%d,x2=%d", p, q);
        }
        else if (d = 0)
        {
            deltaZero(a, b, c);
            printf("x1=x2=%d", p);
        }
        else
        {
            deltaLessZero(a, b, c);
            printf("x1=%d,x2=%d", p, q);
        }
    }
    else
    {
        m = -(c / b);
        printf("x=%d", m);
    }
    return 0;
}

void deltaZero(float a, float b, float c)
{
    n = (-b) / (2 * a);
}
void deltaLargerZero(float a, float b, float c)
{
    p = (-b - sqrt(d)) / (2 * a);
    q = (-b + sqrt(d)) / (2 * a);
}
void deltaLessZero(float a, float b, float c)
{
    p = (-b - sqrt(d)) / (2 * a);
    q = (-b + sqrt(d)) / (2 * a);
}