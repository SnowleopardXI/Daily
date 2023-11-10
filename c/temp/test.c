#include <stdio.h>
#include <math.h>

int main()
{
    double entropy = 0;
    double p[3] = {1.0 / 7, 2.0 / 7, 4.0 / 7};

    for (int i = 0; i < 3; i++)
    {
        entropy -= p[i] * log2f(p[i]);
    }
    printf("信息熵为：%lf\n", entropy);

    return 0;
}