#include<stdio.h>
#include<math.h>
#define N 20
int main(void)
{
    int a[N],i,j,k,flag,count=0;
    for(i=3;i<=20;i++)
    {
        flag=0;
        k=sqrt(i);
        for(j=2;j<=k;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            a[count]=i;
            printf("a[%d]=%d\n",count,a[count]);
            count++;
        }
    }
    return 0;
}
