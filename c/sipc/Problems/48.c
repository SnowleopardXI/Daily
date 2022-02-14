#include<stdio.h>
#include<string.h>
int main()
{
	int i,c,a=0,j,b=0;
	char str[80];
	gets(str);
	for(i=0;i<strlen(str);i++)
	{
		if(i>=1)
		{
			for(j=i-1;j>=0;j--)
			{
				b=0;
				if(str[i]==str[j])
				{
					b++;
					break;
				}
			}
		}
		if(str[i]>='A'&&str[i]<='Z'&&b==0)
		{
			printf("%c",str[i]);
			a++;
		}		
	}
	if(a==0)
		printf("Not Found");
	return 0;
}