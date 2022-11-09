#include <iostream>
int main()
{
	int sum = 0, val = 10;
	//当val>=0时语句执行
	while (val > 0)
	{
		sum = val;
		--val;
		std::cout << sum << std::endl;
	}
	return 0;
}//倒序输出10到0

