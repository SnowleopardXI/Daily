#include <stdio.h>
int main()
{
    int sum=0,count=0;
    while (count<10)
    {
        if (sum%3==2&&sum%5==3&&sum%7==2)
        {
            printf("%d\t",sum);
            count++;
        }
        sum++;
    }
    return 0;
}