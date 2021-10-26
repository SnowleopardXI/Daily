#include <stdio.h>
int main()
{
    int x = 0;
    while (x >= 0 && x <= 1000)
    {
        if (x % 7 == 0 && x % 13 == 0)
            printf("%d ", x);
        x++;
    }
    return 0;
}