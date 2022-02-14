#include <stdio.h>
int main()
{
    int n, i, j;
    float a[100], x;
    while (~scanf("%d", &n))
    {
        for (i = 0; i < n; i++)
            scanf("%f", &a[i]);
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                    x = a[i], a[i] = a[j], a[j] = x;
            }
        }
        x = 0;
        for (i = 1; i < n - 1; i++)
        {
            x = x + a[i];
        }
        x = x / (n - 2);
        printf("%.2f\n", x);
    }
    return 0;
}
