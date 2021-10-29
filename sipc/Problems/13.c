
#include<stdio.h>
#include<stdlib.h>
 
void main(void)
{
	int num[100];
	int index=0;
	int temp=0;
	int result=0;
	while(1)
	{
		scanf("%d",&temp);
			num[index]=temp;
			index++;
	}
	temp=0;
	for (temp = 0; temp < index; temp++)
	{
		result+=num[temp];
	}
	printf("%f",result/index);
	system("pause");
}