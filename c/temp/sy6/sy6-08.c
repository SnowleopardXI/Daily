#include <stdio.h>
int main()
{
	char str1[80] = {""}, str2[80] = {""};
	int i, letter = 0, number = 0, other = 0, blank = 0;
	gets(str1);
	getchar();
	gets(str2);
	for (i = 0; str1[i]!='\0'; i++)
	{
        if(str1[i]==32||str1[i]=='\n')
        blank++;
        else
        {
            if((str1[i]>='a'&&str1[i]<='z')||(str1[i]>='A'&&str1[i]<='Z'))
            letter++;
            else
            {
                if(str1[i]>='0'&&str1[i]<='9')
                number++;
                else
                {
                    if (str1[i]!=32)
                    {
                        other++;
                    }
                    
                }
            }
        }
	}
	printf("String1: Letter:%d,Number:%d,Blank:%d,Other:%d\n", letter, number, blank, other);
	letter = 0, number = 0, other = 0, blank = 0;
	for (i = 0; str2[i]!='\0'; i++)
	{
        if(str2[i]==32||str2[i]=='\n')
        blank++;
        else
        {
            if((str2[i]>='a'&&str2[i]<='z')||(str2[i]>='A'&&str2[i]<='Z'))
            letter++;
            else
            {
                if(str2[i]>='0'&&str2[i]<='9')
                number++;
                else
                {
                    if (str2[i]!=32)
                    {
                        other++;
                    }
                    
                }
            }
        }
	}
	printf("String2: Letter:%d,Number:%d,Blank:%d,Other:%d\n", letter, number, blank, other);
	return 0;
}
