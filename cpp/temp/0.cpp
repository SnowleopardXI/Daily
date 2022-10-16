#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[101];
void change(char s[])
{
	int len=strlen(s);
	for (int i=0,j=len-1; i<j; i++,j--)
		{ char c=s[i]; s[i]=s[j]; s[j]=c; }
}
int main()
{
	cin>>s;
	change(s);
	cout<<s<<endl;
	return 0;
}