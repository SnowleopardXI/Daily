#include <stdio.h>
void paixu(int *q,int n)
{
    int *addr=q;
	int x,y,temp;
	for(x=0;x<n-1;x++)
	{
        q=addr;
		for(y=0;y<n-1-x;y++)
		{
            q=addr;
			if(*(q+y)<*(q+y+1))
			{
				temp = *(q+y);
				*(q+y) = *(q+y+1);
				*(q+y+1) = temp;
			}
		}
	} 
}
int main()
{
    int a[10], i;
    int *p;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    p = a;
    paixu(p, 10);
    for (i = 0; i < 10; i++)
        printf("%d", a[i]);
    return 0;
}
