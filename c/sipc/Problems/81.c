#include<stdio.h>
int main()
{
    int x,y;
    scanf("%d %d",&x,&y);
	int a[x][y];
	int i,j;
	for(int i =0 ; i < x; i++ )
	{
	    for(j =0 ; j < y ; j++)
			scanf("%d",&a[i][j]);
	}
	for(i =0 ; i< y; i++ )
	{
		for(int j =0 ; j < x ; j++)
			printf("%d ",a[j][i]);
		printf("\n");
	}
	return 0;
}
