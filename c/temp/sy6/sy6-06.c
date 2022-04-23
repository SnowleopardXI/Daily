#include <stdio.h>
void sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
//Binary Search
int binarySearch(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int a[10],i,target;
    printf("Please input 10 numbers: ");
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a, 10);
    printf("Please input the target: ");
    scanf("%d",&target);
    if (binarySearch(a, 10, target) == -1)
        printf("%d is not in the array\n", target);
    else
        printf("%d is in the array\n", target);
    return 0;
}