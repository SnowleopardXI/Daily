/*One possible version*/
#include<stdio.h>
#include<math.h>
int prime(int n){		//判断是否为质数 
	int k = sqrt(n);
	for(int i=2;i<=k;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}
int minyueshu(int n){	//求n除了1以外的最小约数 
	int k;
	for(int i=2;i<n;i++){
		if(n%i==0){
			return i;
		}
	}
	return 0;
}
int main(){
	for(int i=3;i<300;i++){
		if(prime(i)){		//当i本身为质数时跳过 
			continue;
		}
		if(prime(minyueshu(i))&&prime(i/minyueshu(i))){
			printf("%d,",i);
		}
	}
} 
