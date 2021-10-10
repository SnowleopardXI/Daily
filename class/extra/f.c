#include <stdio.h>
int main()
{
    long i, n, t1 = 0, t2 = 1, next;
    printf("输出几项: ");
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);
        next = t1 + t2;
        t1 = t2;
        t2 = next;
    }
    return 0;
}