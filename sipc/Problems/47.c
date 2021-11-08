#include <stdio.h>
int main()
{
	int i;
	char c[81]={0};
	gets(c);
	for(i=0; c[i]; i++)
		if(c[i]>=65&&c[i]<=90)
			c[i]=26-(c[i]-'A'+1)+'A';
	puts(c);
	return 0;
}
