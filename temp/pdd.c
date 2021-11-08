#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    float price,price0,div,evil0;
    int i,n,count0,count1=0,count2=0,count3=0;
    srand(time(0));
    printf("请输入金额：");
    scanf("%f",&price0);
    price+=rand()%((int)price0-(int)(price0-rand()%31));
    div=price0-price-(1.0*rand()/RAND_MAX *(1-0));
    evil0=price0-div;
    printf("恭喜你，原价%.2f元,现已砍成 %.2f元，还需%.2f元\n",price0,div,evil0);
    do
    {
        float eviltemp=1.0*rand()/RAND_MAX *(1-0);
        evil0-=eviltemp;
        printf("恭喜你已砍%f元，还需%f元\n",eviltemp,evil0-eviltemp);
    } while (evil0>=0.1);
    
}