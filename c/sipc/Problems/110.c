#include<stdio.h>
int main()
{
    int n=20,i,j,a[200],temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(a[j+1]>a[j]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    return 0;
}
