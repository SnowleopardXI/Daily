#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void game() {
    int rand_num=rand()%100+1;
    int inp;
    while (1)
    {
        printf("Input a number:\n");
        scanf("%d",&inp);
        if (inp<rand_num)
            printf("Small");
        else if(inp>rand_num)
            printf("Larger");
        else if(inp=rand_num){
            printf("Correct");
            break;
        }
    }
void menu()

}
