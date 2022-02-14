#include <stdio.h>
#include <math.h>
int main()
{
    int x,y,i,j;
    //long long square=0,cube=0;
    int square=0,cube=0;
    while (~scanf("%d %d",&x,&y))
    {
        if (x>y)
        {
            i=y;
            y=x;
        }
        else i=x;
        for (i; i <=y; i++)
        {
            if (i%2==0) 
            square+=pow(i,2);
            else 
            cube+=pow(i,3);          
        }
        printf("%d %d\n",square,cube);
        square=0,cube=0,x=0,y=0;
    }
    return 0;
}