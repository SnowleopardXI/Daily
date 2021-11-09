#include <stdio.h>
int main()
{
    char str[80]={""};
    char stat='m';
    int i,count=0;
    scanf("%s",str);
    getchar();
    scanf("%c",&stat);
    for (i = 0; str[i]!='\0'; i++)
    {
        if (str[i]==stat)
        count++;
    }
    printf("%d",count);
    return 0;
}