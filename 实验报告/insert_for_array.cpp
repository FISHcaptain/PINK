//已有一个已正序排好的9个元素的数组，今输入一个数要求按原来排序的规律将它插入数组中。
#include<stdio.h>
int InsertForArray1(int a[10], int x)
{
	int temp = 0;
	for (int i = 0; i < 9; i++) {
		if (x <= a[i]) {
			temp = a[i];
			a[i] = x;
			x = temp;
		}//这一步是想遍历数组然后找出数组和x中最大的值储存
	}
	a[9] = x;
	//这个程序并不能解决问题，每次输出x都排在最后一位，但是我实在找不出问题。==》之前输出的for循环不应该是在插入的for循环里面设置输出值
	return 0;
}