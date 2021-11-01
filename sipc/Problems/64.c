#include <stdio.h>
int main()
{
    int a1,a2,b1,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    if (b1==0||b2==0)
        return 0;
    float midd1,midd2;
    midd1=(float)a1/b1,midd2=(float)a2/b2;
    if (midd1-midd2<0)
        printf("%d/%d < %d/%d",a1,b1,a2,b2);
    else 
    {
        if (midd1-midd2>0)
        printf("%d/%d > %d/%d",a1,b1,a2,b2);
        else
        printf("%d/%d = %d/%d",a1,b1,a2,b2);
    }
    printf("\n");
    return 0;
}