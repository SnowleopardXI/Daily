#include <stdio.h>
int main(void)
{
    int in;
    printf("请输入大于100的整数");
    scanf("%d",&in);
    printf("%d\t",in%10);
    printf("%d",in/10%10);
    return 0;
}
