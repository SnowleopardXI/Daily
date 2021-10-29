#include<stdio.h>
int main()
{
	int n=10,r,i,m=0,j=1,k;
	while(n<=100)
	{
		k=n,m=0,r=0;
		while (k!=0)//求反序数
		{
			r=r*10+k%10;
			k/=10;
		}
		for(i=2;i<=n-1;i++)	//判断n是否为素数
		{	
			if(n%i==0) 
			{	
				m=1;
				break;
			}
		}
		for(i=2;i<=r-1;i++)//判断r是否为素数
		{	
			if(r%i==0) 
			{	
				m=1;
				break;
			}
		}
		if(m==0) 
		{	
			printf("%d ",n);
			if(j%5==0) 
			printf("\n");
			j++;
		}
		n++;
	}
	return 0;
} 
