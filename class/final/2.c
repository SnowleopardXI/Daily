#include <stdio.h>
#include <math.h>
int isPrime(int x)
{
    int i;
    for (i = 2; i < (int)sqrt(x); i++)
    {
        if(x%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int i,j,w,q,b,s,g,count=1;
    for (i = 10000; count <= 10; i++)
    {
        w=i/10000;
        q=i/1000%10;
        b=i/100%10;
        s=i/10%10;
        g=i%10;
        for (j=0; j < 10; j++)
        {
            if (w+q+b+s+g==4*j+1&&isPrime(i))
            {
                printf("%d  ",i);
                count++;
                break;    
            }
        }
    }
    return 0;
}