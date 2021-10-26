#include<stdio.h>
int main()
{
    int m, n, temp, i;
    scanf("%d%d", &m, &n);
    if(m<n)  
    { 
        temp=m;
        m=n;
        n=temp;
    }
    for(i=n; i>0; i--) 
        if(m%i==0 && n%i==0)
        {
            printf("The GCD of %d and %d is: %d\n", m, n, i);
            break;
        }
    return 0;
}