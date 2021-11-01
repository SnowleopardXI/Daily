#include<stdio.h>
#include<string.h>
int main()
{
	char a[100000];
	gets(a);
	int m, i, j;
	m = strlen(a);
	if (a[0] == ' ')
		j = 0;
	else
		j = 1;
	for (i = 0; i<m - 1; i++)
	{
		if (a[i] == ' ' && a[i + 1] != ' ')
			j++;
	}
	printf("%d\n", j);
	return 0;
}
