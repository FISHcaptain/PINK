#include <iostream>
int main()
{
	std::cout << "Enter two numbers" << std::endl;//����������������
	int a = 0, b = 0;//�����������������ı���
	std::cin >> a >> b;//��ȡ��������
	while (a-1> b)
	{
		++b;
			std::cout << b << std::endl;
	}
	while (b - 1 > a)
	{
		++a;
		std::cout << a << std::endl;
	}

	return 0;//��while���ʵ�����������������֮���ֵ
}

