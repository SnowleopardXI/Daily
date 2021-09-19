#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char inp[20]={0};
    int i=0;
    for(i=0;i<10000;i++)
    {
        scanf("%s",inp);
        if(strcmp(inp,"cjbtql")==0)
        {
            printf("The password is correct\n");
        break;
        }
        else
        {
            printf("Password error, please input again\n");
        }
    }
    return 0;
}