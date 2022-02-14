#include <stdio.h>
int main()
{
    int x=0,a=0,b=0;
    do
    {
       x++;
       if (x%5==0)
       {
           if (x%3==0)
            a++,b++;
            else a++;
       }
        else 
        {
            if (x%3==0)
            b++;
        }
    } while (x<200);
    printf("5:%d\t3:%d",a,b);
    return 0;
}