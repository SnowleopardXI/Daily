#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int x,y;
	y=1;
	//for (y=1;y<10;)
    	y=((x=3*y,x+1),x-1);
	printf("x=%d,y=%d",x,y);
}
