#include<stdio.h>
int main()
{
	char flag=' ';
	int n,i,j;
	scanf("%d",&n);
	int num[n];
	for (i = 0; i < n&&flag!='\n'; i++)
	{
		scanf("%d",&num[i]);
        flag=getchar();
	}
	
	for(i=0;i<10;i++)
		for(j=0;j<9-i;j++){
			int temp;
			if(num[j]<num[j+1]){
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	for(i=0;i<n;i++)
	printf("%d ",num[i]);
	return 0;
}