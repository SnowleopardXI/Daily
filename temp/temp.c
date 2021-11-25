#include<stdio.h>
#include<math.h>
int main()
{
	int q,i=2;
	for(q=3;q<300;q++)
	{
		for(i=2;i<q;i++)
		{
		if(q%i==0)
		break;
		printf("%d\t",q);
		}
	}
	return 0;
}
