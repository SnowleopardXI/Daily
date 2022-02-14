#include<stdio.h>
int main(void)
{
	char c,b[82];
	int index=-1;
	scanf("%c",&c);
	getchar();
	gets(b);
	for(int i=0;b[i]!='\0';i++)	
		if(b[i]==c)
			index=i;
	if(index==-1)
		printf("Not Found\n");
	else
		printf("index = %d\n",index);
}
