#include<stdio.h>
int main()
{
	int n,i;
	double max,min,sum=0;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		sum+=a[i];
	}
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
			max=a[i];
	}
	min=a[0];
	for(i=0;i<n;i++)
	{
		if(min>a[i])
			min=a[i];
	}
	printf("average = %.2f\nmax = %.2f\nmin = %.2f",sum/n,max,min);
    return 0;
}