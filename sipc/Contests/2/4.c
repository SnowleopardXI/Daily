#include<stdio.h>
int main()
{
    int a,b,i;
    scanf("%d%d",&a,&b);
    for (i = 0; a < b; i++)
    {
        if (a<b)
        {
            a=a*2;
        }
    }
    printf("%d",i);
    return 0;
}