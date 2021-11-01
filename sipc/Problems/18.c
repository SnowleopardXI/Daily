#include <stdio.h>
#include <math.h>
int main()
{

    int number;
    char ch;
    int n;
    int i, j, k;
    scanf("%d %c", &number, &ch);
    n = sqrt((number + 1) / 2);
    int res = number - (2 * n * n - 1);
    for (i = n; i >= 1; i--)
    {
        for (k = 1; k <= n - i; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    for (i = 2; i <= n; i++)
    {
        for (k = 1; k <= n - i; k++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("%c", ch);
        }
        printf("\n");
    }
    printf("%d\n", res);
    return 0;
}