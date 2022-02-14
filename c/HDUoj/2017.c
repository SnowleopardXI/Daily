#include <stdio.h>
int main()
{
    int cnt, i, n;
    char str[1000];
    scanf("%d", &n);
    while (n--)
    {
        cnt = 0;
        scanf("%s", str);
        i = 0;
        while (str[i] != '\0')
        {
            if (str[i] <= '9' && str[i] >= '0')
                cnt++;
            i++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}