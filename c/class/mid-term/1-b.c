#include <stdio.h>
int main()
{
    int sum=0,count=0,i=0;
    while (count<10)
    {
        if (sum%3==2&&sum%5==3&&sum%7==2)
        {
            if(i%5==0)
            printf("\n");
            printf("%d  ",sum);
            count++;
            i++;
        }
        sum++;
    }
    return 0;
}