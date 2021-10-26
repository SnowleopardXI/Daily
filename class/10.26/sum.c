#include <stdio.h>
int main()
{
    int x=2,y=1,i,y1;
    float sum=0;
    for ( i = 0; i < 20; i++)
    {
        sum=sum+((float)x/y);
        y1=y,y=x,x=y1+x;
    }
    printf("%.2f",sum);
    return 0;
}