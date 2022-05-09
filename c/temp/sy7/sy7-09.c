#include<stdio.h>
#define N 8
int biosearch(int a[],int key);
int main(void)
{
    int a[N]={11,22,33,44,55,66,77,88},i,x,find;
    printf("请输入要查找的数：");
    scanf("%d",&x);
    find=biosearch(a,x);
    if(find==-1)
        printf("没找到 %d!\n",x);
    else
        printf("a[%d]=%d",find,x);
    return 0;
}
int biosearch(int b[],int key)
{
    int low,high,mid;
    low=0;
    high=N-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key<b[mid])
            high=mid-1;
        else if(key>b[mid])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}