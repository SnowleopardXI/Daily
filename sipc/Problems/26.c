#include<stdio.h>
#include<math.h>
int main(void)
{
	int n,m,i,j,count=0;     
	scanf("%d", &n);
	for (i=2; i<=n; i++)
    {
		m=pow(2,i)-1;
		for (j=2; j<=sqrt(m); j++)
        {
			if (m%j==0)
				break;
		}
		if (j>sqrt(m))
        {
			printf("%d\n", m);
			count++;
		}
	}
	if (count==0)
		printf("None");
	return 0;
 } 
