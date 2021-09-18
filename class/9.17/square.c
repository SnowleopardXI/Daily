#include <stdio.h>
#include <math.h>
int main()
{
	printf("please input:\n");
	float a1,a2,r1,r2,ri1,ri2; //(所有值为浮点)定义两个正方形边长a1 a2，正方形内接圆半径r1 r2,正方形外接圆半径ri1 ri2
	scanf("%f %f",&a1,&a2);//输入两个边长a1 a2
	r1=a1*1.00/2,r2=a2*1.00/2;//计算两正方形内接圆半径r1 r2
	ri1=r1*sqrt(2),ri2=r2*sqrt(2);//计算两正方形外接圆半径ri1 ri2
	printf("the perimeter of the first square is %.2f\n",4.00*a1);
	printf("the area of the first square is %.2f\n",a1*a1);
	printf("the inner radius of the first square is %.2f\n",r1);
	printf("the outer radius of the first square is %.2f\n",ri1);
	printf("the perimeter of the second square is %.2f\n",4.00*a2);
	printf("the area of the second square is %.2f\n",a2*a2);
	printf("the inner radius of the second square is %.2f\n",r2);
	printf("the outer radius of the second square is %.2f\n",ri2);
	return 0;
}
