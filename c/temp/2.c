#include <stdio.h>

void main()
{
	float C,F;   //声明变量
	printf("请输入当前摄氏温度：\n");//输入温度;   
	scanf_s("%f", &C,4);
	F= C*9/5.0+ 32;   //计算华氏温度
	printf("对应华氏温度为：%.2f\n", F);   //输出华氏温度
}
