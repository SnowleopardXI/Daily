#include <stdio.h>
int Fibonacci(int n)
{
    int i, f1 = 0, f2 = 1, f3;
    if(n == 0||n==1)
        return n;
    for (i = 2; i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}
int main()
{
    int n;
    printf("Please input n: ");
    scanf("%d", &n);
    printf("Fibonacci(%d)=%d\n", n, Fibonacci(n));
    return 0;
}