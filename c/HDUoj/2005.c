/*
Problem Description
给定一个日期，输出这个日期是该年的第几天。

Input
输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。

Output
对于每组输入数据，输出一行，表示该日期是该年的第几天。

Sample Input
1985/1/20
2006/3/12

Sample Output
20
71
*/
#include <stdio.h>

int is_run(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return 1;
	else if (year % 400 == 0)
		return 1;
	else
		return 0;
}

int days(int year, int month)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 2:
		if (is_run(year))
			return 29;
		else
			return 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	default:
		return -1;
	}
}

int main()
{
	int year, month, day;
	int i;
	while (~scanf("%d/%d/%d", &year, &month, &day))
	{
		int count = 0;
		for (i = 1; i < month; ++i)
		{
			count += days(year, i);
		}
		count += day;
		printf("%d\n", count);
	}
	getchar();
	return 0;
}
