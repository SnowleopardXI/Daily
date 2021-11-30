#include <stdio.h>
int sum(int *a,int size)
{
    int i,sum=0;
    //int size=sizeof(a)/sizeof(a[0]);
    printf("sum - Size of a =%d ,size of a[0]=%d\n",sizeof(a),sizeof(a[0]));
    for ( i = 0; i < size; i++)
    {
        sum+=a[i];
    }
    return sum;
}
int main()
{
    int a[]={1,2,3,4,5};
    int size=sizeof(a)/sizeof(a[0]);
    int total=sum(a,size);
    printf("Sum = %d\n",total);
    printf("Main - Size of a =%d ,size of a[0]=%d\n",sizeof(a),sizeof(a[0]));
    return 0;
}