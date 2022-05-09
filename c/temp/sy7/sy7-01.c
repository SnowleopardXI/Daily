#include<stdio.h>
int main(void)
{
    int i,a[10];
    printf("请输入10个整数：\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    printf("您输入的10个整数是：\n");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}