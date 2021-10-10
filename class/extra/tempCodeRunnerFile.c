#include <stdio.h>
int main()
{
    int i;
    float min,max,num[100];
    scanf("%f",&num{i});
    min=num[0],max=num[0];
    for(i=1;i<100;i++)
    {
        if(min>num[i])
        min=num[i];
        if(max<num[i])
        max=num[i];

    }
    printf("Max is %f Min is %f",max,min);
    return 0;
    
}