#include<stdio.h>
#include<math.h>
int main(){
	int i,j,num;
	const double pi=3.1415926535,r,h;
	while(1){
		printf("1-Ball\n2-Cylinder\n3-Cone\nother-Exit\nPlease enter your command:\n");
		scanf("%d",&num);
		switch(num){
			case 1:{
				printf("Please enter the radius:\n");
				scanf("%lf",&r);
				printf("%.2lf\n",4.0/3*pi*pow(r,3));
				break;
			}
			case 2:{
				printf("Please enter the radius and the height:\n");
				scanf("%lf %lf",&r,&h);
				printf("%.2lf\n",pi*pow(r,2)*h);
				break;
			}
			case 3:{
				printf("Please enter the radius and the height:\n");
				scanf("%lf %lf",&r,&h);
				printf("%.2lf\n",1.0/3*pi*pow(r,2)*h);
				break;
			}
			default:
			return 0;
		}
	}
	return 0;
} 