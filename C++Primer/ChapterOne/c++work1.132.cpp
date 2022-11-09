#include <iostream>
int main()
{
	std::cout <<"enter two numbers"<< std::endl;
	int a=0, b=0,c=0;
	std::cin >>a >> b;
	for (; a - b > 1;) {
		++b;
		std::cout << b << std::endl;
	}
		for (; b - a > 1;) {
			++a;
				std::cout << a << std::endl;
		}
	return 0;
}//用for语句实现输出任意两个整数之间的值
