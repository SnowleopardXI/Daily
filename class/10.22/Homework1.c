#include <stdio.h>
int main()
{
    int i=1,d3=0,d5=0;
    for (i = 1; i <= 200; i++)
    {
        if(i%3==0)
        d3++;
        if (i%5==0)
        d5++;
    }
    printf("能被三整除的有%d个，能被5整除的有%d个",d3,d5);
	return 0;
}
