#include<iostream>
using namespace std;
class tofu {
	friend void test();//友元函数的声明
	friend class ctest;//友元类的声明
public ://访问范围说明符
	int pub_;
	void pub_fun(){}
protected :
	int pro_;
	void pro_fun(){}
private :
	int pri_;
	void pri_fun(){}
};
class ctest {
public :
	void z()
	{
		tofu a;
		a.pro_fun();//友元函数可以访问protected成员也可以访问private成员
		int z = a.pro_;//友元类可以访问protected函数也可以访问private函数
	}
};//在访问权益上protected比private多一个子类可以访问
int main()
{
	tofu::eat;//tofu这个类中的一个对象
	eat.pub_;//类变量也就是eat可以访问public成员
	eat. pub_fun;//类变量也可以访问public成员函数
	return 0;
}