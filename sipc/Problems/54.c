#include <stdio.h>
int main()
{
    int n,i;
    scanf("%f",&n);
    float average=0,score[100],max,min;
    for (i = 0; i < n; i++)
    {
        scanf("%f",score[i]);
    }
    min=score[0];
    max=score[0];
    for (i = 0; i < n; i++)
    {
        if (score[i]<min)
            min=score[i];
        if(score[i]>max)
            max=score[i];
        average+=score[i];
    }
    average/=n;
    printf("%.2f %.2f %.2f",max,min,average);
    return 0;   
}