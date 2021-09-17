#include <stdio.h>
int main()
{
 int a,b,c,m; 
 scanf("%d %d %d",&a,&b,&c); 
 if(a>b)
 {
  m = a,a = b,b = m;
 }
 if(a>c) 
 {
  m = a,a = c,c = m;
 }
 if(b>c) 
 {
  m = b,b = c,c = m;
 }
 printf("%d %d %d",a,b,c); 
 return 0;
}