#include <stdio.h>
#include <string.h>

int main()
{
    char mima[100]="cjbtql";
    char input[100]={0};
    start:
    gets(input);
    if(strcmp(mima,input)==0)
        printf("The password is correct\n");
    else
        printf("Password error, please input again\n");
        goto start;
}