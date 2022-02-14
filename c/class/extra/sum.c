#include <stdio.h>
int isPerfectNum(int n)
{
    int i, s = 0, flag = 0;
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
            s += i;
    }
    if (n == s)
    {
        flag = 1;
    }
    return flag;
}
int main()
{
    int m, n, i, sum = 0;
    printf("输入正整数m.n:");
    scanf("%d%d", &m, &n);
    for (i = m; i <= n; i++)
    {
        if (isPerfectNum(i))
        {
            sum += i;
            printf("sum=%d ", sum);
        }
    }
    return 0;
}