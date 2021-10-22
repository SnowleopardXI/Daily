#include<stdio.h>
int main()
{
    char flag='a';
    int n,i,j,temp,temp1;
    scanf("%d",&n);
    int *num[n];
    for (i = 0; i < n&&flag!='\n'; i++)
    {
        scanf("%d",&num[i]);
        flag=getchar();
    }
    for (i = 0; i < n; i++)
    {
        j=i+1;
        temp1=max(num[i],num[i++]);
        num[j]=temp1;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d",num[i]);
    }
}

int max(int x,int y)
{
    int temp;
    if (x<y)
    {
        temp=x;
        x=y;
        y=temp;
    }
    return (x);
}