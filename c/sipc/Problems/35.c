#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[n];
    for (i=0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    int max=0, min=0;
    for (i=1; i < n; i++)
    {
        if (a[i]>a[max])
            max = i;
        if (a[i] < a[min])
            min = i;
    }
    int temp;
    temp = a[min];
    a[min] = a[0];
    a[0] = temp;

    if (max == 0)
        max = min;
    temp = a[max];
    a[max] = a[n-1];
    a[n-1] = temp;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}