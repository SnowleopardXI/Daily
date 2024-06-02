#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s;
	printf("Enter a string: ");
	scanf("%s", &s);
	int flag = strcmp(s, "1");
	printf("%d", flag);
}