#include <iostream>
int main()
{
	int a = 50,b;
	for (b = 101; b >= 52; --b)
		a += b;
	std::cout << "the sum of 50 to 100'sinclusive" << "is" << a << std::endl;
	return 0;
}
//for语句输出50到100的和
