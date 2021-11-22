#include<stdio.h>
struct Person
{
	char name[10];
	int birthday;   
	char number[17];
}Person;
int main(void)
{
	struct Person person[11],temp;  
	int n;
	scanf("%d", &n);
	getchar();   
	for (int i = 1; i <= n; i++)
	{
		scanf("%s %d %s", &person[i].name, &person[i].birthday, &person[i].number);
		getchar();   
	}
	for (int i = 1; i < n; i++)   
	{
		for (int j = i + 1; j <=n; j++)   
		{
			if (person[j].birthday < person[i].birthday)
			{
				temp = person[j];
				person[j] = person[i];
				person[i] = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%s %d %s\n", person[i].name, person[i].birthday, person[i].number);
	}
	return 0;
}