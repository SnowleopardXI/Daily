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
