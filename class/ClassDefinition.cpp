#include <iostream>
using namespace std;
class fruit
{
public:
    fruit() {
        cout << "这是构造函数被调用了 " << endl;
    }
    fruit(int a, int b, int c) {
        cout << "这是构造函数2被调用了 " << endl;
        m_a_ = a;
        m_b_ = b;
        m_c_ = c;
    }
    ~fruit() {
        cout << "这是析构函数被调用了 " << endl;
    }
public:
    void init(int a_, int b_, int c_); //成员函数，设置水果售价，购买数量，原价。
    int price(); //成员函数， 求水果总价
    int dollar(); //成员函数，求卖出水果后的利润
private:
    int m_a_;
    int m_b_;
    int m_c_; //成员变量,水果售价，购买数量，原价
}; //这部分是一个类的定义

void fruit::init(int a, int b, int c)
{
    m_a_ = a;
    m_b_ = b;
    m_c_ = c;
}

int fruit::price()
{
    return m_a_ * m_b_;
}//成员函数的定义

int fruit::dollar()
{
    return (m_a_ - m_c_) * m_b_;
}//成员函数的定义

int main()
{
    int a, b, c;
    fruit r;  //r是一个对象
    cin >> a >> b >> c;
    r.init(a, b, c);//使用类的成员函数和成员定义
    cout << "It's price is " << r.price() << endl;
    cout << "It's dollar is " << r.dollar() << endl;
    //cout << sizeof(fruit) << endl;
    fruit r2(a, b, c); //构造了第二个类对象
    return 0;
}