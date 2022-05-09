#include<stdio.h>
#define N 10
void Sort(int a[],int n);
double GetAverage(int a[],int n);
int main(void)
{
    int a[N],i,n;
    double ave;
    printf("请输入实际评委数(<=10)：");
    scanf("%d",&n);
    printf("请输入%d个评委的成绩：\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    Sort(a,n);
    printf("按由小到大的顺序后的成绩如下：\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    ave=GetAverage(a,n);
    printf("\n该名选手的最后得分为：%.2f\n",ave);
    return 0;
}
void Sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
double GetAverage(int a[],int n)
{
    int i,sum=0;
    //去掉最高分和最低分
    for(i=1;i<n-1;i++)
        sum+=a[i];
    return (double) sum/(n-2);
}