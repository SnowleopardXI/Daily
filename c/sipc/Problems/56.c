#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    char a[n][81];
    int max = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        if (strlen(a[i]) > strlen(a[max]))
            max = i;
    }
    printf("The longest is: %s\n", a[max]);
    return 0;
}