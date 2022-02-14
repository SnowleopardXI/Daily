#include <stdio.h>
int main()
{
    int i,j,k,l,pos=0,x;
    int array[10]={1,2,4,6,7,9,12,15,18,20};
    int out[11];
    scanf("%d",&x);
    for (i = 0; i < 10; i++)
    {
        if (x<array[i])
		break;
		pos++;      
    }
    for (j = 0; j < pos; j++)
    {
        out[j]=array[j];
    }
    out[pos]=x;
    for (k = pos+1; k <= 11; k++)
    {
        out[k]=array[k-1];
    }
    for (l = 0; l < 11; l++)
    {
        printf("%d ",out[l]);
    }
    return 0;   
}