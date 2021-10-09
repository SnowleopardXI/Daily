#include <stdio.h>
int main() 
{
	int x,n;
	printf("输入一个整数：");
  	scanf("%d",&x);
  
  	if (x<=0||x>=10000)
		printf("输入错误");
  	else if(x>999)
		n=4;
   		else if(x>99)
  			n=3;
    		else if(x>9)
  				n=2;
     			else if(x>1)
  					n=1;
		printf("整数的位数为：%d位",n);

	return 0;
}
