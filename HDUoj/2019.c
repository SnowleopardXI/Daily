#include<stdio.h>
int main()
{
	int n,m,val;
	while(~scanf("%d %d",&n,&m))
	{
		if(m==0&&n==0)
			break;
		if(n==0)
		{
			printf("%d\n",m);
			break;
		}
		else
		{
			int i,j,flag=1;
			for(i=0; i<n ;i++)
			{
				scanf("%d",&val);
				if(flag&&val>= m)
				{
					if(i==0)
						printf("%d",m);
					else
						printf(" %d",m);
					flag=0;
				}
				if(i>0 || !flag)
					printf(" ");
				printf("%d",val);
			}
			printf("\n");
		}
	}
    return 0;
}
