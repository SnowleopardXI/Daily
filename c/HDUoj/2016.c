#include<stdio.h>
void main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int a[100];
        int min=100000;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]<min)
            {
                min=a[i];
                flag=i;
            }
        }
        if(flag!=0)
        {
            a[flag]=a[0];
            a[0]=min;
        }
        printf("%d",a[0]);
        for (int j=1;j<n;j++)
            printf(" %d",a[j]);
        printf("\n");
    }
}