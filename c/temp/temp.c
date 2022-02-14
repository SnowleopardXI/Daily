#include <stdio.h>
#include <string.h>
void Shift(char s[])
{
	int i = 0,j = 0;
	int num = strlen(s);
	for (i = 0; i < 3; i++)
	{
		char a = s[0];
		for (j = 1; j < num; j++)
		{
			s[j - 1] = s[j];
		}
		s[num - 1] = a;
	}
}
int main()
{
	char s[100]={"\0"};
	gets(s);
	Shift(s);
	puts(s);
	return 0;
}
