#include <stdio.h>
/*int GetSum(int n)
{
 int c;
 int sum=0;
  for(c=1;c<n;c++)
 {
  if(n%c==0)
  {
   sum=sum+c;
 }
 
 } */
int isCompleteNumber(int n)
{
	int c;
	int sum;
	sum = 0;
	for (c = 1; c < n; c++)
	{
		if (n % c == 0)
		{
			sum = sum + c;
			if (n == GetSum(n))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
}
int main()
{
	int n;
	for (n = 2; n <= 10000; n++)
	{

		if (isCompleteNumber(n) == 1)
		{
			printf("%d为完数", n);
		}
		else
		{
			return 0;
		}
	}
}