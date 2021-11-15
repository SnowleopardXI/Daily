#include <stdio.h>
int main()
{
    int n,i,pos=0,add,temp;
    scanf("%d",&n);
    int ori[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&ori[i]);
    }
    scanf("%d",&add);
    for ( i = 0; i < n; i++)
    {
        if (add<ori[i])
            pos++;
    }
    //printf("%d",pos);
    for ( i = n; i > pos; i--)
    {
        ori[i]=ori[i-1];
    }
    ori[pos-1]=add;
    for (i = 0; i <=n; i++)
    {
        printf("%d ",ori[i]);
    }
    return 0;
}