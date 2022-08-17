/*
Problem Description
给定一段连续的整数，求出他们中所有偶数的平方和以及所有奇数的立方和。

Intput
输入数据包含多组测试实例，每组测试实例包含一行，由两个整数m和n组成。

Output
对于每组输入数据，输出一行，应包括两个整数x和y，分别表示该段连续的整数中所有偶数的平方和以及所有奇数的立方和。
你可以认为32位整数足以保存结果。

Sample Intput
1 3
2 5

Sample Output
4 28
20 152
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int x,y,i,j;
    //long long square=0,cube=0;
    int square=0,cube=0;
    while (~scanf("%d %d",&x,&y))
    {
        if (x>y)
        {
            i=y;
            y=x;
        }
        else i=x;
        for (i; i <=y; i++)
        {
            if (i%2==0) 
            square+=pow(i,2);
            else 
            cube+=pow(i,3);          
        }
        printf("%d %d\n",square,cube);
        square=0,cube=0,x=0,y=0;
    }
    return 0;
}
