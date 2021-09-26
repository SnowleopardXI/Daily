#include <stdio.h>
int main()
{
    char c1,c2,temp;
    scanf("%c %c",&c1,&c2);
    temp=c1,c1=c2,c2=temp;
    printf("%d,%d\n",c1,c2);
    return 0;
} 
