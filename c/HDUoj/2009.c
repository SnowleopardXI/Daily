/*
Problem Description
数列的定义如下：
数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。

Intput
输入数据有多组，每组占一行，由两个整数n（n<10000）和m(m<1000)组成，n和m的含义如前所述。

Output
对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。

Sample Intput
81 4
2 2

Sample Output
94.73
3.41
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int m,n,i;
    double t,sum;
    while(~scanf("%d%d",&n,&m)){
        t=n,sum=0;
        for(i=0;i<m;i++){
            sum+=t;
            t=sqrt(t);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
