#include <stdio.h>
int main()
{
    char x;
    int i,letter=0,blank=0,digit=0,other=0;
    for (i = 0; i < 10; i++)
    {
        scanf("%c",&x);
        if(x==32||x=='\n')
        blank++;
        else
        {
            if((x>='a'&&x<='z')||(x>='A'&&x<='Z'))
            letter++;
            else
            {
                if(x>='0'&&x<='9')
                digit++;
                else
                {
                    if (x!=32)
                    {
                        other++;
                    }
                    
                }
            }
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
    return 0;
}
