/*Problem Description
输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。

Input
输入数据有多组，每组占一行，有三个字符组成，之间无空格。

Output
对于每组输入数据，输出一行，字符中间用一个空格分开。

Sample Input
qwe
asd
zxc

Sample Output
e q w
a d s
c x z
*/
#include <stdio.h>
int main()
{
    char a, b, c, min, mid, max;
    while (scanf("%c%c%c\n", &a, &b, &c) != EOF)
    {
        if (a <= b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }
        if (min >= c)
        {
            mid = min;
            min = c;
        }
        else
        {
            if (c > max)
            {
                mid = max;
                max = c;
            }
            else
            {
                mid = c;
            }
        }
        printf("%c %c %c\n", min, mid, max);
    }
    return 0;
}
