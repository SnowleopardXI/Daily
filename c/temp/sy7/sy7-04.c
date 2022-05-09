#include<stdio.h>
#define N 30
int main(void)
{
    int a[N],i=0,sum=0;
    double ave;
    do
    {
        printf("请输入成绩：");
        scanf("%d",&a[i]);
        if(a[i]<0)
            break;
        sum+=a[i];
        i++;
    } while (1);
    ave=sum/(i-1);
    printf("\n总分=%d，平均分=%.2f\n",sum,ave);
    return 0;
}