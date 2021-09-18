#include <stdio.h>
#include <string.h>

int main()
{
    char mima[50]="cjbtql";
    char input[50]={0};
    start:
    gets(input);
    if(mima==input)
        printf("The password is correct\n");
    else
        printf("Password error, please input again\n");
        goto start;
}