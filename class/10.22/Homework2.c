#include <stdio.h>
int main()
{
    float n;
    int i,n2=1;
    printf("请输入一个正整数:");
    scanf("%f",&n);
    while ((n-(int)n!=0)||(n<=0))
    {
        printf("输入的不是正整数，请重试!\n");
        scanf("%f",&n);
    }
    for (i=1; i<=(int)n; i++)
    {
        n2*=i;
    }
    printf("%d的阶乘是%d",(int)n,n2);
    return 0;
}
