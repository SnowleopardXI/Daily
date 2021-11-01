#include <stdio.h>
#define PI 3.141592653
int main(void)
{
    int cho;
	double rad,hei,out;
    printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
	scanf("%d",&cho);
	while (cho==1||cho==2||cho==3)
	{
    	switch (cho)
   		{
    		case 1:
        		printf("Please enter the radius:\n");
        		scanf("%lf",&rad);
        		out=4*PI/3*rad*rad*rad;
        		printf("%.2f\n",out);
    		case 2:
    	    	printf("Please enter the radius and the height:\n");
        		scanf("%lf %lf",&rad,&hei);
        		printf("%.2f\n",PI*rad*rad*hei);
    		case 3:
        		printf("Please enter the radius and the height:\n");
        		scanf("%lf %lf",&rad,&hei);
        		printf("%.2f\n",PI/3*rad*rad*hei);
    		default:
        		break;
    	}		
	}
	return 0;
}
