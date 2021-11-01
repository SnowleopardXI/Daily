#include <stdio.h>
int main(void)
{
	int a[10000] = {NULL}; 
	int i = 0, n;
	double sum = 0.0; 
	double average = 0.0; 
	scanf("%d", &n); 
	for (i = 0; i < n; i++) 
	{
		scanf("%d", &a[i]); 
		sum += a[i]; 
	}
	printf("%d",(int)sum);
	average = sum / (double)n;
	printf(" %.1lf", average); 
	return 0;
}