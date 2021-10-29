#include <stdio.h>
int main()
{
    int j=2;
    double sum;
    do
    {
        sum+=(1.0/j);
        j+=2;
    } while (1.0/j>=(10e-7));
    printf("%lf",sum);
    return 0;
}
