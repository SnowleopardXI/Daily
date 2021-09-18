#include<stdio.h>
void main() 
{
    int n,x,m,i;
    scanf("%d",&n);
    for ( i=0;i<n;i++ ) {
        scanf("%d",&x); if ( i==0 ) m=x; 
    else 
    if ( x<m ) m=x;
  }
  printf("min = %d\n",m);
}