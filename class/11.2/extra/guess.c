#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
void game() {
    int rand_num=rand()%100+1;
    int inp;
    while (1)
    {
        printf("Input a number:\n");
        scanf("%d",&inp);
        if (inp<rand_num)
            printf("Small\n");
        else if(inp>rand_num)
            printf("Larger\n");
        else if(inp=rand_num){
            printf("Correct\n");
            break;
        }
    }
}
void menu(){
    printf("1.Start\n");
    printf("2.End\n");
    }
int main(){
    int choice;
    menu();
    srand((unsigned int)time(NULL));
    while(1) {
        printf("Input:\n");
        scanf("%d",&choice);
        if(choice==1) {
            game();
            }
        else if(choice==2) {
            break;
            }
        else printf("Error\n");
            continue;
        }
    return 0;
}
