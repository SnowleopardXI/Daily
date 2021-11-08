#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a[10],i,j,x,flag=0,temp;
    srand(time(0));
    for (i = 0; i < 10; i++)
    {
        a[i]=rand()%21+5;
    }
    /*printf("Please input a number:");
    scanf("%d",&x);
    for (i = 0; i < 10; i++)
    {
        if (a[i]==x)
        {
            printf("%d is found at index %d.",a[i],i);
            break;
        }
        else
            flag++;
    }
    if (flag==10)
        printf("Not found");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");*/
    for(i=0;i<10-1;i++){
        for(j=0;j<10-1-i;j++){
            if(a[j]<a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                }
            }
        }
    for ( i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}