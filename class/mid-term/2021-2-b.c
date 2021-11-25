#include <stdio.h>
int isPrime(int x)
{
    int i,bool=0;
    for (i = 2; i < x; i++)
    {
        if (x%i==0)
        {
            bool++;
            return 1;
        }      
    }
    return 0;
}
int main()
{
    int i,j;
    for (i = 3; i <= 300; i++)
    {
        if(isPrime(i)||isPrime(i+2))
        continue;
        printf("%d/%d\t",i,i+2);
    }
    return 0;
}