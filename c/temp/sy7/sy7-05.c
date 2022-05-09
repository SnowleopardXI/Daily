#include<stdio.h>
#define N 8
int main(void)
{
    int a[N]={7,9,4,3,6,2,5,1},i;
    int max=a[0];
    for(i=0;i<N;i++)
        if(max<a[i])
            max=a[i];
    printf("最大值是%d\n",max);
    return 0;
}