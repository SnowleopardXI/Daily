#include<stdio.h>
#define N 30
int main(void)
{
    int a[N],n,i,count;
    count=0;
    printf("请输入实际学生数(<=30)：");
    scanf("%d",&n);
    printf("请输入%d名学生的成绩："),n;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\n不合格的成绩如下：\n");
    for(i=0;i<n;i++)
    {
        if(a[i]<60)
        {
            printf("%d ",a[i]);
            count++;
        }
    }
    printf("\n共有不及格学生%d名\n",count);
    return 0;
}