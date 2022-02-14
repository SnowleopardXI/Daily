#include <stdio.h>
int main()
{
    int age,price;
    scanf("%d",&age);
    if (age<=10||age>=70)
        price=0;
    else
        price=20;
    printf("%d\n",price);
    return 0;
}