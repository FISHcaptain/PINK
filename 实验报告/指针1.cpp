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
/*��Ŀ�Ǳ�д�������㲢��������е�ʮ������ƽ���������������������ƽ���ɼ���Ҫ��ֱ��������ָ����Ϊ��������*/
//�Ҹо��ҵĺ����Ĳ������õ�̫���ˣ��ǲ���ֻ�������ָ�����������Ϳ��ԴﵽЧ��
