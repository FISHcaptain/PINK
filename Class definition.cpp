#include <iostream>
using namespace std;
class fruit
{
public:
    int a,b,c; //成员变量,水果售价，购买数量，原价
    void init(int a_, int b_,int c_); //成员函数，设置水果售价，购买数量，原价。
    int price(); //成员函数， 求水果总价
    int dollar(); //成员函数，求卖出水果后的利润
}; //这部分是一个类的定义
void fruit::init(int a_, int b_,int c_)
{
    a = a_;  b = b_; c = c_;
}
int fruit::price()
{
    return a*b;
}//成员函数的定义
int fruit::dollar()
{
    return (a-c)*b;
}//成员函数的定义
int main()
{
    int a,b,c;
    fruit a;  //a是一个对象
    cin >> a>> b>>c;
    r.init(a,b,c);//使用类的成员函数和成员定义
    cout << "It's price is " << a.price() << endl;
    cout << "It's dollar is " << a.dollar();
    cout << sizeof(fruit) << endl;
    return 0;
}