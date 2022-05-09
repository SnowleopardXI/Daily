#include<stdio.h>
void fun(int b[]);
int main(void)
{
    int a[]={1,2,3,4,5,6,7,8},i;
    fun(a);
    for(i=0;i<8;i++)
    {
        if((i+1)%4==0)
            printf("\n");
        printf("%d ",a[i]);
    }
}
void fun(int b[])
{
    int i;
    for(i=0;i<4;i++)
    {
        b[i]=2*b[i]+1;
    }
}