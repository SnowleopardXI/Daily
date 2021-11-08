#include <stdio.h>
int main()
{
  int hour,min,sec0,seci;
  scanf("%d:%d:%d",&hour,&min,&sec0);
  scanf("%d",&seci);
  sec0+=seci;
  if(sec0>=60)
  {
    sec0-=60;
    min++;
  }
  if(min>=60)
  {
    min-=60;
    hour++;
  }
  if(hour>=24)
  {
    hour-=24;
  }
  printf("%02d:%02d:%02d",hour,min,sec0);
  return 0;
}}
