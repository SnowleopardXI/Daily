#include <stdio.h>
int main()
{
    char str[81];
    int sum=0,i,j=0;
    gets(str);
    for ( i = 0; str[i]!=0; i++)
    {
        if ((str[i]>='0'&&str[i]<='9')||(str[i]>='A'&&str[i]<='F')||(str[i]>='a'&&str[i]<='f'))
        {
            str[j]=str[i];
            j++;
        }
    }
    for ( i = 0; i < j; i++)
    {
        printf("%c",str[i]);
    }
    return 0;
}