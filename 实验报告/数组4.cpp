//计算等差数列前n项和
#include <stdio.h>
#define N 10000
int main()
{
	int n, sum = 2;
	int p[N] = { 0 }；
		scanf_s("%d", &n);
	p[0] = 2;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] + 3;
		sum += p[i];
	}
	printf("%d", sum);
	return 0;
}




