#include <stdio.h>
int main()
{
    char str1[80]={""};
    int i,j;
    gets(str1);
    for (i = 0; str1[i]!='#'; i++)
    {
        if (str1[i]>='a'&&str1[i]<='z')
            str1[i]-=32;
        else
        {
            if (str1[i]>='A'&&str1[i]<='Z')
            str1[i]+=32;
        }
    }
    //printf("%d",i);
    for ( j = 0; j < i; j++)
    {
        printf("%c",str1[j]);
    }
    printf("\n");
    return 0;
}
