#include <iostream>
int main()
{
	int sum = 0, val = 50;
	//ֻҪval��ֵС�ڵ���100��whileѭ���ͻ����ִ��
	while (val <= 100) {
		sum += val;//��sum+val��ֵ����sum
		++val;    //��val��1
	}
	std::cout << "sum of 50 to 100 inclusive is"
		<< sum << std::endl;
	return 0;
}//50��100�ĺͣ� while���

