#include <stdio.h>
#include <string.h>
int main()
{
    char passwd[100],encrypted[100];
    int i,j,k,t,move=3;
    scanf("%s;",&passwd);
    for(i=0; i<strlen(passwd); i++)
    {
 
 		if(passwd[i] >= 'a' && passwd[i] <= 'z')
        {
            passwd[i] = ((passwd[i]-'a')+move)%26+'a';
        }else if(passwd[i]==';')
        {
        	passwd[i]='\0';
		}
    }
    printf("%s",passwd);
    return 0;
}