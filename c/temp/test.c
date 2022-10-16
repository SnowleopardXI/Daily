#include<stdio.h>
#include<math.h>
double total(double m,int n)
{
	if(n==1)  return m;
	else return total(m,n-1)+m/pow(2,n-2);
} 
int main()
{
	int i,j;
	int n;
	double m;
	scanf("%lf%d",&m,&n);
	double gaodu=m/pow(2,n);
	double zong=total(m,n);
	printf("%.2lf %.2lf",gaodu,zong);
 }