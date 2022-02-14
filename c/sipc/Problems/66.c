#include<stdio.h>
#include<math.h>
#define M acos(-1)
int main()
{
	int m;
	double h,r,V;
	while(1)
	{
		printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
		scanf("%d",&m);
		if(m==1)
		{
			printf("Please enter the radius:\n");
			scanf("%lf",&r);
			V=4*M*r*r*r/3;
			printf("%.2lf\n",V);continue;
		}
		else if(m==3)
		{
			printf("Please enter the radius and the height:\n");
			scanf("%lf%lf",&r,&h);
			V=M*r*r*h/3;
			printf("%.2lf\n",V);
		}
		else if(m==2)
		{
			printf("Please enter the radius and the height:\n");
			scanf("%lf%lf",&r,&h);
			V=M*r*r*h;
			printf("%.2lf\n",V);
		}
		else
		break;
	}
	return 0;
}