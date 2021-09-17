#include <stdio.h>
int main()
{
      int input;
      scanf("%d",&input);
      if (input<10||input>=60)
      {
            printf("40");
            return 0;
      }
      printf("80");
      return 0;
}