#include<stdio.h>
int main()
{
    int num[10000],i;
    for (i = 0; i < 10000; i++)
    {
        scanf("%d",&num[i]);
    }
    for (i=0;i<10000;i++)
    {
        if(num[i]%2!=0&&num[i]%3==0)
        printf("%d",num[i]);
    }
    return 0;
}