/*
Problem Description
输入n(n<=100)个整数，按照绝对值从大到小排序后输出。题目保证对于每一个测试实例，所有的数的绝对值都不相等。

Input
输入数据有多组，每组占一行，每行的第一个数字为n,接着是n个整数，n=0表示输入数据的结束，不做处理。

Output
对于每个测试实例，输出排序后的结果，两个数之间用一个空格隔开。每个测试实例占一行。

Sample Input
3 3 -4 2
4 0 1 2 -3
0

Sample Output
-4 3 2
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, a[100], temp;
    while (~scanf("%d", &n))
    {
        if (n == 0)
            break;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (abs(a[j]) < abs(a[j + 1]))
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }
        printf("%d", a[0]);
        for (i = 1; i < n; i++)
        {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
