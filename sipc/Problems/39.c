#include<stdio.h>
#include<string.h>
int main()
{
	int n,m,i,j,k,ret=0;
	scanf("%d",&n);
	int b[n];
	for(i=0;i<n;i++)
		b[i]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		int a[m][m];
		for(j=0;j<m;j++)
		{
			for(k=0;k<m;k++)
				scanf("%d",&a[j][k]);
		}
		for(j=1;j<m;j++)
		{
			for(k=0;k<j;k++)
			{
				if(a[j][k]!=0)
				{
					b[i]=1;
					break;
				}
			}
		}
		if(m==1&&a[0][0]!=0)
		b[i]=1;	
	}
	for(i=0;i<n;i++)
	{
		if(b[i])
			printf("NO\n");
		else
			printf("YES\n");
	}
}