#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, p, square;
    printf("Enter the value of a, b, c: ");
    scanf("%f%f%f", &a, &b, &c);
    p = (a + b + c) / 2;
    if (a + b > c && a + c > b && b + c > a)
    {
        square = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("The area of the triangle is %f", square);
    }
    else
    {
        printf("The given values are not a triangle\n");
    }
    return 0;
}