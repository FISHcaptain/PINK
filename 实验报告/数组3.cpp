//�ݹ鵹���ַ�����
#include<stdio.h>
int main() {
	char a[1000], temp;
	int n, i;
	scanf_s("%d", &n);
	getchar();
	gets_s(a);
	for (i = 0; i < n / 2; i++) {
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
		puts(a);
	}
	printf("\n");
	puts(a);
	return 0;//Ϊɶ�������������ĸֻ�����ĸ���
}




