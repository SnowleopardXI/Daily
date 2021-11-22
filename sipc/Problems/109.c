#include<stdio.h>
int main()
{
	int a,b,count=0;
	scanf("%d %d",&a,&b);
	do{
		a*=2;
		count++;
	}while(a<=b);
	printf("%d",count);
	return 0;
}