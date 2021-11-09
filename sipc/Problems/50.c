#include <stdio.h>
int main()
{
    char ch[82]={""};
    int i,j=0,out[32];
    scanf("%s",ch);
    for (i = 0; i < 80; i++)
    {
        if (ch[i]>='0'&&ch[i]<='9')
        {
            out[j]=(int)ch[i]-48;
            j++;
        }
    }
    for (i = 0; i < j; i++)
    {
        printf("%d",out[i]);
    }
    return 0;
}