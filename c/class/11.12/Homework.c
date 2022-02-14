#include <stdio.h>
int main()
{
    int a[10] ={1,2,4,6,7,9,12,15,18,20};
    int i,j,temp,n,z;
    printf("请输入任意一个整数: ");
    scanf("%d",&n);
    a[10] = n;
    for (i=10; i<11; i++) 
    {
        for (j=0,z=n; i>j && z==n; j++)
        {
            if (a[j] > a[i])
            {
                temp=a[i];
                while (i>j)
                {
                    a[i]= a[i-1];
                    i--;
                }
                a[i]=temp;
                z=0;
            }
        }
    }
    printf("插入一个数后的排列结果为: ");
    for (i=0; i<11; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}