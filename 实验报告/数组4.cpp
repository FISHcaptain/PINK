//����Ȳ�����ǰn���
#include <stdio.h>
#define N 10000
int main()
{
	int n, sum = 2;
	// �Ż���1: ����ÿ��ֻ��һ����ǰ�ӵ����֣����ô���������
	// v1 = 2�� v2 = v1 +3
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
	// ǿ���汾 ������쳲���������
}




