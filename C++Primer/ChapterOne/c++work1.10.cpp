#include <iostream>
int main()
{
	int sum = 0, val = 10;
	//��val>=0ʱ���ִ��
	while (val > 0)
	{
		sum = val;
		--val;
		std::cout << sum << std::endl;
	}
	return 0;
}//�������10��0

