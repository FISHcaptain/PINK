#include <stdio.h>
int zjn(int a[10], int* p);
int main()
{
	int a[10], * p;
	p = &a[0];
	for (p = a; p < a + 10; p++) {
		scanf_s("%d", p);
	}
	int zjn(int a[10], int* p);
	{
		for (p = a + 9; p >= a; p--)
			printf("%d\n", *p);
	}
	return 0;
}//题目为利用指针和数组倒序输出数组，并且输出要在主函数，我这个是不是输出在重新定义的那个函数了啊？

// 你这个并没有实现倒序的功能，而且输出在功能函数里面了。你只是倒序遍历输出了一遍
// 题目是希望你将数组 1  2 3 通过功能函数转成 3 2 1的数组，然后输出这个结果数组
