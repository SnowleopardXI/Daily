#include <stdio.h>
int main(void)
{
    int in;
    printf("请输入大于100的整数\n");
    scanf("%d",&in);
    printf("The first digit is %d\t",in%10);
    printf("The second digit is %d",in/10%10);
    return 0;
}
