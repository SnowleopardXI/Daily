#include <stdio.h>
int mod=10000010;

int main(void)
{
    int c,n,a,b,i,sum=0,next;
    scanf("%d %d %d",&a,&b,&n);
    int array[n];
    array[0]=a,array[1]=b;
    for (i = 1; i <= n; i++)
    {
        next=f(a+b);
        array[i+1]=next;
        a=array[i],b=array[i+1];
    }
    for ( i = 0; i < n-1; i++)
    {
        sum+=array[i];
    }
    printf("%d",sum);
    return 0;
}

int f(int x,int y)
{
    return ((x+y)>mod)?x+y-mod:x+y;
}