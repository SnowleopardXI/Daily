#include <stdio.h>
int main()
{
    int i,sum=0;
    char str[80];
    gets(str);
    while (str[i])
    {
        if (str[i]>='0'&&str[i]<='9')
            sum=sum*10+str[i]-'0';
        i++;
    }
    printf("%d",sum);
    return 0;
}