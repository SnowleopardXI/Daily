#include <stdio.h>
int main()
{
	int m, n;
	while (~scanf("%d", &m))
	{
		while (m--)
		{
			scanf("%d", &n);
			double ans = 0;
			for (int i = 1; i <= n; i++)
			{
				if (i % 2 == 0)
					ans = ans - (double)(1.0 / i);
				else
					ans = ans + (double)(1.0 / i);
			}
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}