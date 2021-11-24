#include <stdio.h>
int main()
{
	int i=0;
	while(++i)
	{
		if (i==10)
		break;
		if (i%3!=1)
		continue;
		printf("%d ",i);
	}
	return 0;
}