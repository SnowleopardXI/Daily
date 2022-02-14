#include <stdio.h>
int main()
{
    int i = 0;
    do
    {
        if (i % 7 == 0 && i % 13 == 0)
            printf("%d ", i);
        i++;
    } while (i <= 1000);
    return 0;
}