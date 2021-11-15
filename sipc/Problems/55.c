#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,length=0;
    scanf("%d",&n);
    char ori[80]={""},result[80]={""};
    for (i = 0; i < n; i++)
    {
        scanf("%s",ori);
        if ( strlen(ori)>length)
        {
            length=strlen(ori);
            strcpy(ori,result);
        }   
    }
    puts(result);
    return 0;
}