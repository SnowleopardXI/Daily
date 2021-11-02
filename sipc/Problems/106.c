#include <stdio.h>
int main()
{
    char x;
    int a;
    scanf("%c",&x);
    if(x>=49&&x<=57)
    {
        a=(x-48)*2;
        printf("%d",a);
        return 0;
    }
    x=(x>=65&&x<=90)?x+32:(x>=97&&x<=122)?x-32:x;;
    printf("%c",x);
    return 0;
}