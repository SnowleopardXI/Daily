#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Reverse(char str[], char ptr[]);
int main()
{
    char str[100];
    char ptr[100];
    gets(str);
    Reverse(str,ptr);
    printf("%s",ptr);
}
void Reverse(char str[], char ptr[]){
    int n=strlen(str);
    int i;

    for(i=0;i<=n;i++){
        ptr[i]=str[n-i-1];
    }
    ptr[i-1]='\0';
}