#include <stdio.h>
int main()
{
    char s1[20]={""},s2[20]={""};
    gets(s1);
    convert(s1, s2);
    //printf("\n");
    puts(s2);
    return 0;
}
void convert(char *p, char *q)
{
    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
            *q = *p + 32;
        else
            *q = *p;
        p++;
        q++;
    }
}
