#include <stdio.h>
int main()
{ 
    int i,n;
    double e=1,t=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {   
        t/=i;
        e+=t;
    }
    printf("%.8f\n",e);
    return 0;
}