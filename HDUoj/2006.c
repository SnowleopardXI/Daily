#include<stdio.h>
int main()
{
    int a,n,i,sum;
    while(~scanf("%d",&a))
    { 
        sum=1;
        for(i = 0 ;i <a ;i++)
        {  
            scanf("%d",&n);
            if(n%2!=0)
            sum*=n;
        }
    printf ("%d\n",sum);
    }
    return 0;
}