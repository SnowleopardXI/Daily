#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

//判断两个数是否互素 
bool Isprime(int a,int b){
	if(__gcd(a,b)==1){
		return true;
	}else{
		return false;
	}
}

//快速幂取余 
int fastpower(LL a,LL b,LL p){
	LL res=1;
    while(b){
        if(b&1)res=res*a%p;
        b=b>>1;
        a=a*a%p;
    }
    return res;
} 


int main(){
	//97的所有本原根为：5 7 10 13 14 15 17 21 23 26 29 37 38 39 40 41 56 57 58 59 60 68 71 74 76 80 82 83 84 87 90 92 
	LL p=97,a=5;//p是大素数 a是p的本原根 
	LL Xa=36,Xb=58;//Xa 和 Xb为随机保密整数 
	LL Ya=fastpower(a,Xa,p),Yb=fastpower(a,Xb,p);//Ya=(a^Xa)%p Yb=(a^Xb)%p 
	LL Ka=fastpower(Yb,Xa,p),Kb=fastpower(Ya,Xb,p);//Ka=(Yb^Xa)%p Kb=(Ya^Xb)%p
	
	cout<<Ka<<" "<<Kb;
}

