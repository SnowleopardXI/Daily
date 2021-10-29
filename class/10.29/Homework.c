#include<stdio.h>
int main()
{
    int one, two, five;//type=0;
    for(one = 0; one <= 100; one++)            
    { 
        for (two = 0; two <= 50; two++)          
        {
            for (five = 0; five <= 20; five++)      
            {
                if (one + 2 * two + 5 * five == 100&&one*two*five!=0&&(one+two+five)==30)  
                {
                    //type++;
                    printf("100元钱可兑换为 ：%d个一元，%d个2元，%d个5元\n", one, two, five); 
                    printf("\n");
                }
            }
        }
    }
    //printf("%d",type);
    return 0;
}