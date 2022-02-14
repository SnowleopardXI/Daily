#include <stdio.h>
//#include <string.h>
int main()
{
    char str[10]="China";
    //printf("%d",strlen(str));
    int i,len=0;
    for (i = 0; str[i]!='\0'; i++)
    {
        len++;
    }
    printf("%d",len);
    return 0;
}
