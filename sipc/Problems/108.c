#include<stdio.h>
int main()
{
	int n;
  	while (scanf("%d",&n) != EOF)
    {
        if(n%2 !=0 && n%3 == 0)
        printf("%d ",n);
    }
  return 0;
}