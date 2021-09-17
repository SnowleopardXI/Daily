#include <stdio.h>
int main(void)
{
    int in=368;
    printf("请输入大于100的整数 368\n");
    printf("The first digit is %d\t",in%10);
    printf("The second digit is %d",in/10%10);
    return 0;
}
