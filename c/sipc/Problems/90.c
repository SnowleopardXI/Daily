#include<stdio.h>
#include<math.h>
int judgment_prime(int n);
int main()
{
    int m=1,n;
    scanf("%d",&n);
    int i,k=0;
    for(i=m+1;i<=n;i++)
    {
        if(judgment_prime(i)==1)
        k++;
    }
    printf("%d",k);
}

int judgment_prime(int n)
{
    int i,k=1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            k=0;
            break;
        }
    }
    return k;
}