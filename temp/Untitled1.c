#include <stdio.h>
int main()
{
    float n;
    int i;
    long long n2=1;
    printf("������һ��������:");
    scanf("%f",&n);
    while ((n-(int)n!=0)||(n<=0))
    {
        printf("����Ĳ�����������������!\n");
        scanf("%f",&n);
    }
    int n1=n;
    for (i=1; i<=n1; i++)
    {
        n2*=i;
    }
    printf("%d�Ľ׳���%lld",n1,n2);
    return 0;
}

