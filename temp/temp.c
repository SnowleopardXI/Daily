#include<stdio.h>
int main()
{
	int i,a[10]={1,2,3,4,5,6,7,8,9,10},b;
	scanf("%d",&b);
	for(i=0;i<=9;i++)
	{
		if(a[i]>b)
		break;
	}
	int c[11]={b,1,2,3,4,5,6,7,8,9,10};
	printf("%d ",b);
	for(i=0;i<=10;i++)
	{
		printf("%d ",c[i]);
	}
	return 0;
}
