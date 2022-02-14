#include <stdio.h>
int main()
{
    int n,i,j,array[10],midd,min;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    min=array[0];
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(array[j+1]>array[j]){
                midd=array[j];
                array[j]=array[j+1];
                array[j+1]=midd;
                }
            }
        }
    for (i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}