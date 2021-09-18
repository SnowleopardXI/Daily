#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  time_t ti;
  int num, guess;
  /* 初始化随机数发生器 */
  srand((unsigned)time(&ti));
  num = rand() % 100;
  printf("随机数已生成，开始游戏\n");
  while (true){
    printf("请猜一个数字：");
    scanf("%d", &guess);
    if (guess > num)
      printf("猜大了\n");
    else if (guess < num)
      printf("猜小了\n");
    else
    {
      printf("猜对了\n");
      break;
    }
  }
  system("pause");
  return 0;
}