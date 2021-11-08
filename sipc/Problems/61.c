#include <stdio.h>
#include <stdlib.h>
struct book
{
    char name[62];
    float price;
}
s[10]={0};
int main()
{
    int n,i,min,max;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%s\n%f",&s[i].name,&s[i].price);
    }
    min=s[i].price,max=s[i].price;
    for (i = 0; i < n; i++)
    {
        if (s[i].price<min)
            min=s[i].price;
        if (s[i].price>max)
            max=s[i].price;
    }
    printf("%d %s",min,s[i].name);
    return 0;
}