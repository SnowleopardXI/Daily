#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a,b,c;
	c=n%60;
	b=n/60%60;
	a=n/3600;
	printf("%02d:%02d:%02d",a,b,c);
	return 0;
}