#include <iostream>
int main()
{
	std::cout << "Enter two numbers" << std::endl;//提醒输入两个整数
	int a = 0, b = 0;//保存读入的两个整数的变量
	std::cin >> a >> b;//读取输入数据
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

	return 0;//用while语句实现输出任意两个整数之间的值
}

