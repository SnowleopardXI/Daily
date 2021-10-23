#include <stdio.h>

const int mod = 1e9 + 7;
int n, a, b;
int p[10000010], s[10000010];

int add(int a, int b) 
{
	return a + b >= mod ? a + b - mod : a + b;
}

int main() {
	register int i;
	scanf("%d%d%d", &a, &b, &n);
	p[1] = a; p[2] = b;
	s[1] = a; s[2] = add(a, b);
	for(i = 3; i <= n; ++i)
		p[i] = add(p[i - 1], p[i - 2]);
        s[i] = add(s[i - 1], p[i]);
	printf("%d\n", s[n]);
	return 0;
}
