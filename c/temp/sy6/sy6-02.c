#include <stdio.h>
float average(float *a, int n)
{
    float r = 0;
    int i;
    for (i = 0; i < n; i++)
        r += a[i];
    return r/n;
}
int main()
{
    float a[10];
    int i;
    printf("Please input 10 students' score: ");
    for (i = 0; i < 10; i++)
        scanf("%f", a + i);
    printf("%.2f\n", average(a, 10));
    return 0;
}