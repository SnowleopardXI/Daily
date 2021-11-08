#include <stdio.h>
int main()
{
    char str1[80]={""},str2[80]={""};
    int i,j;
    gets(str1);
    for (i = 0; str1[i]!='\0'; i++)
    {
        if (str1[i]!='\0')
            str2[i]=str1[i];
    }
    puts(str2);
    return 0;
}
