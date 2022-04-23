#include <stdio.h>
int gcd(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return m;
}
int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}
int main()
{
    int m, n;
    printf("Please input m,n: ");
    scanf("%d%d", &m, &n);
    printf("gcd(%d,%d)=%d\n", m, n, gcd(m, n));
    printf("lcm(%d,%d)=%d\n", m, n, lcm(m, n));
    return 0;
}