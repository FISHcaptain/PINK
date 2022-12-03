//计算等差数列前n项和
#include <stdio.h>
#define N 10000
int main()
{
	int n, sum = 2;
	// 优化点1: 可以每次只存一个当前加点数字，不用存整个数组
	// v1 = 2， v2 = v1 +3
	// v1 = v2, v2 = v1 + 3
	// ...
	int p[N] = { 0 };
	scanf_s("%d",&n);
	p[0] = 2;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] + 3;
		sum += p[i];
	}
	printf("%d", sum);
	return 0;
	// 强化版本 ，计算斐波那契数列
}




