#include<stdio.h>
long long power(int a,int b)
{
	long long sum=1;
	for(int i=1;i<=b;i++)
		sum=sum*a;
	return sum;
}

int main()
{
	int a,t,i,n;
	long long sum=0;
	scanf("%d",&n);
	for(i=power(10,n-1);i<=power(10,n)-1;i++)
	{
		a=i;sum=0;
		for(int b=1;b<=n;b++)
		{
		    t=a%10;
		    a/=10;
		    sum=sum+power(t,n);
		}
		if((int) sum==i)
		printf("%d\n",i);
	}
}
