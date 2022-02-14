#include<stdio.h>
int main()
{ 
  int n,i,j;
  scanf("%d",&n);
  for(i=0; i<n; i++)
  { 
    for(j=i+1-n; j<2*i+1; j++)
      printf((j>=0&&j<=2*i)?"*":" ");
    printf("\n");
  }
  for(i=n-2; i>=0; i--)
  {
    for(j=i+1-n; j<2*i+1; j++)
      printf((j>=0&&j<=2*i)?"*":" ");
    printf("\n");
  }
  return 0;
}