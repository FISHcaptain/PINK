//递归倒置字符数组
#include<stdio.h>
int ReverseCharArray() {
	char a[1000], temp;
	int n, i;
	scanf_s("%d", &n);
	getchar();
	gets_s(a); // 这里输入是不带空格的
	for (i = 0; i < (n + 1) / 2; i++) {  // n/2  ==> (n+1)/2  4/2=2 5/2=2 理解下为啥5/2等于2
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
		puts(a);
	}
	printf("\n");
	puts(a);
	return 0;//为啥这样我输五个字母只出来四个？
}




