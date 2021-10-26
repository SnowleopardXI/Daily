#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,a[100],temp;
	while(~scanf("%d",&n))
	{if(n==0) break;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(abs(a[j])<abs(a[j+1])){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				}
			}
		}
		printf("%d",a[0]);
		for(i=1;i<n;i++)
		{
			printf(" %d",a[i]);
		}
		printf("\n");
	}
	return 0;
}

