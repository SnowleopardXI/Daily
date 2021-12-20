#include<stdio.h>
int isperfectnum(int x)
{
    int i,s=0;
    for( i=1; i<x; i++ )
    {
        if(x%i == 0)
        s += i;
    }
    if (s==x)
        return 1;
    return 0;
}
int main()
{
    int i,m,n;
    printf("请输入m,n:");
    scanf("%d%d", &m,&n);  
    for( i=m; i<=n; i++ )
    {
        if(isperfectnum(i))
            printf("%d\t", i);
    }
    return 0;
}