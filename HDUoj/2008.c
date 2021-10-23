#include<stdio.h>
int main()
{
    int n,i,a,b,c;
    double t;
    while(~scanf("%d",&n)){
        a=0,b=0,c=0;
        if(n==0){
            break;
        }else{
            for(i=0;i<n;i++){
                scanf("%lf",&t);
                if(t<0){
                    a++;
                }
                if(t==0){
                    b++;
                }
                if(t>0){
                    c++;
                }
            }
        }
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}
