#include<stdio.h>
int main(void)
{
    float s,a[100];
    int i=1;
    for(s=10;s<=20;i++){
    s=s*(1+0.05);
    a[i]=s;
    printf("第%d年收益为%f万元\n",i,a[i]);
    }
    return 0;
}