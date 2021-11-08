#include <stdio.h>
#include <string.h>

int main()
{
    char str[82];
    gets(str);
    int cnt = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            if ((str[i] != 'A') && (str[i] != 'E') && (str[i] != 'I') && (str[i] != 'O') && (str[i] != 'U'))
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}