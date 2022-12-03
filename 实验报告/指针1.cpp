#include <stdio.h>
double zjn(int* p, int a[10]);
int main()
{
	int a[10];
	int* p;
	int sum = 0;
	double aver = 0;
	p = &a[0];
	for (p = a; p < a + 10; p++) {
		scanf_s("%d", p);
		sum += *p;
	}
	double zjn(int a[10], int* p, int sum, double aver); {
		aver = sum / 10;
	}
	printf("%lf", aver);
	return 0;
}
/*题目是编写函数计算并输出数组中的十个数的平均数，并在主函数中输出平均成绩，要求分别用数组和指针作为函数参数*/
//我感觉我的函数的参数设置的太多了，是不是只用数组和指针两个参数就可以达到效果
