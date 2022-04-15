#include <stdio.h>
int main()
{
    int i;
    //不包含数字7和不包含7的倍数的所有数
    for (i = 1; i <= 100; i++)
    {
        if(i%7==0||i%10==7||i/10==7)
            continue;
        printf("%d\t", i);
    }
    return 0;
}