#include <stdio.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    int a[100000];
    for (i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (j = 0; j < n; j++)
    {
        if (a[0]<a[j])
        {
            a[0]=a[j];
            i=j;
        }
        if (a[0]==a[j])
        {
            a[0]=a[j];
            if (i>j)
            i=j;
        }
    }
    printf("%d %d", a[i], i);
    return 0;
}