#include <stdio.h>
int main()
{
    int i=0;
    char ch[200];
    while (~scanf("%c",&ch[i]))
    {
        for (i = 0; i < 80; i++)
        {
            scanf("%c",&ch[i]);
        }
    }
    for (i = 0; i < 80; i++)
    {
        printf("%c ",&ch[i]);
    }
}