#include <stdio.h>
#include <math.h>
int main()
{
    int m,n,i;
    double t,sum;
    while(~scanf("%d%d",&n,&m)){
        t=n,sum=0;
        for(i=0;i<m;i++){
            sum+=t;
            t=sqrt(t);
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}