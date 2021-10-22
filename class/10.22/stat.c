#include <stdio.h>
int main()
{
    int u=0,l=0,n=0;
    char c;
    do
    {
        scanf("%c",&c);
        if (c>=48&&c<=57)
            n++;
        else if(c>=65&&c<=90)
            u++;
        else if(c>=97&&c<=122)
            l++;
    } while (c!='\n');
    printf("Lower :%d\nUpper :%d\nNumber :%d",l,u,n);
    return 0;
}