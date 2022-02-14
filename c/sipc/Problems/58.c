#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char str[40];
	gets(str);
	int count1=0,count2=0,sum=0,flag=0,n=strlen(str),i;
	for(i=0;i<n;i++)
	{
		count1++;
		sum+=(str[i]-'0')*pow(2,7-i+count2);
		if(count1==8)
		{
			count2+=count1;
			count1=0;
			if(flag==0)
			{
				printf("%d",sum);
				flag=1;
			}
			else printf(".%d",sum);
			sum=0;
		}
	}
} 
