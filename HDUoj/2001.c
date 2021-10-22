#include <stdio.h>
#include <math.h>
int main()
{
    float x1,y1,x2,y2,result;
    while(scanf("%f %f %f %f\n", &x1,&y1,&x2,&y2)!=EOF) 
    {
        result=sqrt((pow((x1-x2),2))+(pow((y1-y2),2)));
        printf("%.2f\n",result);
    }
    return 0;
}