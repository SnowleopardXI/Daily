#include<stdio.h>
int main()
{
    char temp;
    long ans = 0;
    while (~scanf("%c",&temp))
        if (temp <= '9' && temp >= '0')
            ans = ans * 10 + temp - '0';
    printf("%ld", ans);
    return 0;
}