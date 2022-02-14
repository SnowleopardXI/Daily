#include <stdio.h>
int main()
{
    int a[10], i, s = 0, c;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 10; i++)
    {
        if (i % 2 != 0)
        {
            printf("0");
        }
        else
        {
            printf("%d ", i);
            s += i;
        }
    }
    printf("\n");
    printf("%d", s);
    return 0;
}

/*int main()
{
    int a[10], i, s = 0, c;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 10; i++)
    {
        if (a[i] % 2 == 0)
        {
            printf("%d ", a[i]);
            c++;
            s += i;
        }
    }
    if (c == 0)
        printf("0");
    else
    {
        printf("\n");
        printf("%d", s);
    }
    return 0;
}
*/