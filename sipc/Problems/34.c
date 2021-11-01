#include <stdio.h>
int main()
{
    int i,n,x,flag=0;
    scanf("%d %d",&n,&x);
    int array[20];
    for (i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    
    for (i = 0; i < n; i++)
    {
        if (array[i]==x)
        {
            printf("%d",i);
            flag++;
            break;
        }
    }
    if (flag==0)
        printf("Not Found");
    return 0;
}