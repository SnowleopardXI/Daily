#include <stdio.h>
#define PRICE 100
int main()
{
    int age,out;
    scanf("%d",&age);
    if(age<0||age>120){
        printf("Invalid");
    }
        
    else
    {
        if(age>=0&&age<=6)
            out=0;
        else 
        {
            if((age>6&&age<=12)||(age>=60&&age<70))
                out=PRICE/2;
            else
            {
                if(age>=70)
                out=0;
                else
                out=PRICE;
            }
        }
        printf("%d",out);
        return 0;
    }
}
