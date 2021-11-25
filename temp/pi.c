#include<stdio.h>
int main()
{
	int i;
    double pi=1,temp;
    for (i =1 ; 1.0/(2*i+1)>0.0001; i++)
    {
        if (i%2!=0)
            temp=-1.0/(i*2+1);
        else
            temp=1.0/(i*2+1);
        pi+=temp;
    }
    printf("%lf",pi*4);
	return 0;
}