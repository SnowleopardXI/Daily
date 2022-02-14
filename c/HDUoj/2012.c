#include <stdio.h>
int func(int m)
{
    return (m * m + m + 41);
}
int main()
{
    int x, y;
    while (~scanf("%d%d", &x, &y))
    {
        int i, j, k = 0, count = 0, temp;
        if (x > y)
        {
            temp = x;
            x = y;
            y = temp;
        }
        if (x == 0 && y == 0)
            break;
        for (i = x; i <= y; i++)
        {
            for (j = 2; j < func(i); j++)
            {
                if (func(i) % j == 0)
                {
                    k++;
                    break;
                }
            }
        }
        if (k != 0)
            printf("Sorry");
        else
            printf("OK");
        printf("\n");
    }
    return 0;
}