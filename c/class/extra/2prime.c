/*#include <stdio.h>
int isPrime(int number)
{
    int i, flag = 1;
    if (number < 11)
        return 0;
    for (i = 2; i < number; i++)
    {
        if (number%i==0)
            return 0;        
    }
    return flag;
}
int main()
{
    int i, n;
    for (i = 10; i < 100; i++)
    {
        n = (i % 10 * 10) + (i / 10);
        /*printf("i=%d\t",i);
        printf(" Inverted=%d\n",n);*/
/*        if (isPrime(i) && isPrime(n))
            printf("%d\t", i);
    }
    return 0;
}*/

#include <stdio.h>
int prime(int x);
int main()
{
    int i = 3;
    for (i = 3; i < 300; i++)
    {
        if (prime(i) && prime(i + 2))
            printf("%d/%d  ", i, i + 2);
    }
    return 0;
}
int prime(int x)
{
    int n, flag = 1;
    for (n = 2; n < x; n++)
    {
        if (x % n == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}