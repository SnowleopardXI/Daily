#include <stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	a /= 10;
	switch(a) {
		case 10: puts("It is our duty to recast the glory of Mieah!"); break;
		case 1: case 2: case 3: case 4: case 5: puts("Wuwuwu");
		case 6: puts("Sad");
		case 7: puts("So-so");
		case 8: puts("Happy");
		case 9: puts("Mieah~"); break;
		default: puts("Mieah?");
	}
	return 0;
}