#include <stdio.h>
int main()
{
    char x;
    scanf("%c",&x);
    x=(x>=65&&x<=90)?x+32:(x>=97&&x<=122)?x-32:x;;
    printf("%c",x);
    return 0;
}