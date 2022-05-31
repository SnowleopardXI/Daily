/*
Problem Description
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。

Intput
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。

Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。

Sample Intput
3 2
4 2

Sample Output
3 6
3 7
*/
#include<stdio.h>

int main()
{
	int n,m;
	while(~scanf("%d%d", &n, &m))
	{
		int sum = 0, a = 2, count = 0, i;
		for(i=1; i<=n; i++)
		{
			sum += a;
			a += 2;
			if(i % m == 0)
			{
				count++;
				if(count != 1)
					printf(" ");
				printf("%d", sum/m);
				sum = 0;	
			}
		 }
		if(n % m == 0)
		 	printf("\n");
		else
			printf(" %d\n", sum/(n%m));  
	}
	return 0;
 } 
