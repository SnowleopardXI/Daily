#include <stdio.h>
int main()
{
    char a, b, c, min, mid, max;
    while (scanf("%c%c%c\n", &a, &b, &c) != EOF)
    {
        if (a <= b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }
        if (min >= c)
        {
            mid = min;
            min = c;
        }
        else
        {
            if (c > max)
            {
                mid = max;
                max = c;
            }
            else
            {
                mid = c;
            }
        }
        printf("%c %c %c\n", min, mid, max);
    }
    return 0;
}