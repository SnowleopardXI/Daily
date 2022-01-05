#include <stdio.h>
char convert(char *ch,char x,char y)
{
    while (*ch!='\0')
    {
        if (*ch==x)
            *ch=y;
        ch++;
    }
}

int main()
{
    char ch[20]={""},x='a',y='Z',*p;
    gets(ch);
    p=ch;
    convert(p,x,y);
    puts(ch);
    return 0;
}