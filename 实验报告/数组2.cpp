//输入十个整数，逆序输出，空格隔开，且最后一个数字不能有空格。
#include<stdio.h>
int main()
{
	int a[10], i;
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 9; i >= 0; i--) {
		printf("%d ", a[i]);
	}
	return 0;
}