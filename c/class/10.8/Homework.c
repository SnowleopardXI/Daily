#include <stdio.h>
int main() 
{
	int input,n;
	printf("输入一个整数：");
	scanf("%d",&input);
	if(input>10000 || input<0)
		printf("输入错误");
	else {
		if(input==10000)
			n=5;
			else if(input>999)
				n=4;
				else if(input>99)
					n=3;
					else if(input>9)
						n=2;
						else if(input>=0)
							n=1;
	printf("整数的位数为：%d位",n);
	}
	return 0;
}
