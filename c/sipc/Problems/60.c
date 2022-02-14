#include <stdio.h>
#include <string.h>
struct student
{
	char sno[11];
	char name[11];
	double grade;
}
s[10]={0};
int main()
{
	int i,n;
	double sum=0,avg;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s %s %lf",&s[i].sno,&s[i].name,&s[i].grade);
	    sum+=s[i].grade;
	}
	avg=sum/n;
	printf("%.2lf\n",avg);
	for(i=0;i<n;i++)
	{
		if(s[i].grade<avg)
		   printf("%s %s\n",s[i].name,s[i].sno);
	}
	return 0;
} 