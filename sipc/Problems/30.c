#include<stdio.h>
int main()
{
	int N,X,i,t,k,j;
	scanf("%d",&N);
	int a[N];
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&X);
	N+=1;
	a[N-1]=X;
    for (i = 0; i < N; i++)
    {
        if (a[i]==X)
        {
            for (j = 0; j < N; j++)
            {
                printf("%d ",a[j]);
            }
            return 0;
        }
    }
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i-1;j++)
	    if(a[j]>a[j+1])
        {
		    t=a[j];
	    	a[j]=a[j+1];
	    	a[j+1]=t;
	    } 
	}
	for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
	return 0;
}