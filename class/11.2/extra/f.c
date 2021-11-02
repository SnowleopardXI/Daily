#include <stdio.h>
int main()
{
    long long i, n, t1 = 0, t2 = 1, next,j;
    scanf("%d", &n);
    for (i = 1; i <= n/5; ++i)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ",t1);
            next = t1 + t2;
            t1 = t2;
            t2 = next;
        }
        printf("\n");
    }
    return 0;
}