#include <stdio.h>
#define PI 3.1415927
int main(void)
{
    int cho;
	double rad,hei,out;
    calc:
    	printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:");
    	scanf("%d",&cho);
    	switch (cho)
    	{
    	case 1:
        	printf("Please enter the radius:\n");
        	scanf("%lf",&rad);
        	out=4*PI/3*rad*rad*rad;
        	printf("%.2f\n",out);
        	goto calc;
    	case 2:
    	    printf("Please enter the radius and the height:\n");
        	scanf("%lf %lf",&rad,&hei);
        	printf("%.2f\n",PI*rad*rad*hei);
        	goto calc;
    	case 3:
        	printf("Please enter the radius and the height:\n");
        	scanf("%lf %lf",&rad,&hei);
        	printf("%.2f\n",PI/3*rad*rad*hei);
        	goto calc;
    	default:
        	break;
    }
}
