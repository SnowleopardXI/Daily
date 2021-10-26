#include <stdio.h>
int main()
{
    int x, i=0, sum = 0,j=0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&x);
        if (x%2==0)
        sum+=x,j++;
    }
    if (((float)sum/j)==(sum/j))
        printf("偶数的和为：%d,其平均值为：%d",sum,sum/j);
    else
    printf("偶数的和为：%d,其平均值为：%.2f",sum,(float)sum/j);
    return 0;
}