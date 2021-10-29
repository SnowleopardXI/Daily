#include<stdio.h>
int main()
{
	double sum=0;
	for(int i=0;;i++)
	{
		double term =1.0/(i*2+1);
		if(i%2==0) 
        sum+=term;
		else 
		sum-=term;
		if(term<1e-6) 
        break;
	}
	printf("%10.8lf\n",sum*4.0);
	return 0;
	
}
