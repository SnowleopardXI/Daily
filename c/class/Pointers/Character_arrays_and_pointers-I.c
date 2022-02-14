#include <stdio.h>
void print(char *C)
{
    int i=0;
    while (C[i]!='\0')
    {
        printf("%c",C[i]);
        i++;
    }
    printf("\n");
}
int main()
{
    char c[20]="Hello";
    print(c);
    return 0;
}