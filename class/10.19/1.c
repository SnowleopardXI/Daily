#include <stdio.h>
int main()
{
    char x;
    x=getchar();
    if(x+5<='z')
    x+=5;
    else if(x+5>'z')
    x=x+4-'z'+'a';
    putchar(x);
    return 0;
}