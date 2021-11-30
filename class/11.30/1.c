#include <stdio.h>
int main()
{
    int a=0,b=0;
    int *p1=NULL,*p2=NULL;
    int *temp=NULL;
    scanf("%d%d",&a,&b);
    p1=&a,p2=&b;
    if (*p1<*p2)
    {
        temp=p1;
        p1=p2;
        p2=temp;
    }
    printf("max = %d, min= %d",*p1,*p2);
    return 0;
}