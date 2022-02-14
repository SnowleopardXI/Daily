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
