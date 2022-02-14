#include <stdio.h>
#include <string.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    char a[n][81],b[81];
    for (i = 0; i < n; i++)
    {
        scanf("%s",a[i]);
    }
    strcpy(b, a[0]);
    for (i = 1; i < n; i++)
    {
        if (strcmp(a[i],b) < 0)
            strcpy(b, a[i]);
    }
    printf("Min is: %s\n",b);
    return 0;
}