#include <stdio.h>
int main()
{
    int j=2,i=0;
    double sum;
    do
    {
        if (i%2!=0)
        sum+=(-1.0/j);
        sum+=(1.0/j);
        j+=2;
        i++;
    } while (1.0/j>=(10e-7));
    printf("%lf",sum);
    return 0;
}