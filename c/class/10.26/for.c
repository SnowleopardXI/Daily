#include <stdio.h>
int main()
{
    int i;
    for (i = 0; i <= 1000; i++)
    {
        if (i % 7 == 0 && i % 13 == 0)
            printf("%d ", i);
    }
    return 0;
}