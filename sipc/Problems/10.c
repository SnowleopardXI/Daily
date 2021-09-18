#include <stdio.h>
#include <math.h>

int main()
{
    int a,c;
    scanf("%d",&a);
    c=floor(a/10);
    switch (c)
    {
    case 10:
    printf("A\n");
    break;
    
    case 9:
    printf("A\n");
    break;

    case 8:
    printf("B\n");
    break;

	case 7:
    printf("C\n");
    break;
    
    case 6:
    printf("D\n");
    break;

    case 5:
    printf("E\n");
    break;

    case 4:
    printf("E\n");
    break;

    case 3:
    printf("E\n");
    break;

    case 2:
    printf("E\n");
    break;

    case 1:
    printf("E\n");
    break;
    case 0:
        
    printf("E\n");
    break;    
    default:
        return 0;
      
    }
}
