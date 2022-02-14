#include <stdio.h>
int main()
{
    char x;
    int num,i;
    scanf("%c%d",&x,&num);
    switch (num)
    {
    case 2:
        i=2;
        break;
    case 3:
        i=3;
        break;
    default:
        printf("error");
        break;
    }
    if(x>=100)
    {
        printf("%d",x);
    }
    else {
        if(x>=65&&i==2)
            printf("%d",(int)x);
        else
            printf(" %d",x);
    }
}