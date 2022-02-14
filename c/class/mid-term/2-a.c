#include <stdio.h>
int main()
{
    int i,sum=0,j,count=0;
    for ( i = 0; count < 5; i++)
    {
        sum++;
        if (sum%2==1&&sum%3==2&&sum%5==4&&sum%6==5&&sum%7==0)
        {
            printf("%d\t",sum);
            count++;
        }
    }
    return 0;
}