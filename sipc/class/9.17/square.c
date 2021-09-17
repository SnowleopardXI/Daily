#include <stdio.h>
#include <math.h>
int main()
{
	printf("please input:\n");
	int a1,a2;
	float r1,r2,ri1,ri2;
	scanf("%d %d",&a1,&a2);
	r1=a1*1.0/2;
	r2=a2*1.0/2;
	ri1=r1*sqrt(2);
	ri2=r2*sqrt(2);
	printf("the perimeter of the first square is %d\n",4*a1);
	printf("the area of the first square is %d\n",a1*a1);
	printf("the inner radius of the first square is %f\n",r1);
	printf("the outer radius of the first square is %f\n",ri1);
	printf("the perimeter of the second square is %d\n",4*a2);
	printf("the area of the second square is %d\n",a2*a2);
	printf("the inner radius of the second square is %f\n",r2);
	printf("the outer radius of the second square is %f\n",ri2);
	return 0;
}
