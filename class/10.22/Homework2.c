#include <stdio.h>
int main()
{
    float n;
    int i,n2;
    scanf("%f",&n);
    while ((n-(int)n!=0)||(n<=0))
    {
        printf("Please retry!\n");
        scanf("%f",&n);
    }
    int n1=n;
    for (i = n1; i >0; i--)
    {
        n1*=i;
    }
    printf("%d的阶乘是%d",n1,n2);
    return 0;
}