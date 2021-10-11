#include <stdio.h>
int main()
{
    int *p,n;
    scanf("%d",&n);
    int i,num[n],sum;
    float average;
    p=num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(p=num;p<(num+n);p++)
    {
        sum+*p;
    }
        average=sum/n;
        printf("%7.2f",average);
    return 0;
}