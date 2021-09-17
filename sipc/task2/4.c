#include <stdio.h>
int main() 
{
    int i,m;
    m=i--;
    scanf("%d",&i);
	void print(int, int);
	int j = 1;
	for (int m) {
		print(i, j);
		j = j + 2;
		printf("\n");
	}

	j = j - 2;
	for (int k = 0; k <= 3; k++) {
		print(k, j);
		j = j - 2;
		printf("\n");
	}
}

void print(int x, int y) {
	for (int i = x; i > 0; i--) printf(" ");
	for (int j = y; j > 0; j--) printf("*");
}