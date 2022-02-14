#include <stdio.h>
#include <math.h>
 
int main()
{
	int m, n, i, t;
	while(~scanf("%d %d", &m, &n))
    {
		if(m > n)
        {
			t = m;               
			m = n;
			n = t;
		}
		double  a, b, c;                 
		int flag = 0;                       
		for(i = m; i <= n; i++)
        {
			a = i / 100;
			b = (i/10) % 10;
			c = i % 10;
			if( i == pow(a,3) + pow(b,3) + pow(c,3))
            {
				if(flag==0)
				{
				    printf("%d", i);
				    flag = 1;
                }
				else 
				printf(" %d", i);        
			}
		}
		if(flag == 0) printf("no");
		printf("\n");
	}
	return 0;
}