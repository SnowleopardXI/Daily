#include <stdio.h>
int main() 
{
  int a,b=1,n,c=0;
  scanf("%d",&n);
  for(a=1;a<=n;++a)
  {
    printf("a=%d",a);
    a=a*b;
    b=a;
  }
  printf("b=%d",b);
  return 0;
}