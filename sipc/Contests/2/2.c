#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    switch (x)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    	printf("%d",x*x);
    	break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    	printf("%d",x*x*x);
        break;
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    	printf("%d",x/2);
    	break;

    default:
        printf("%d",-x);
        break;
    }
}