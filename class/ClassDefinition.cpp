#include <iostream>
using namespace std;
class fruit
{
public:
    fruit() {
        cout << "���ǹ��캯���������� " << endl;
    }
    fruit(int a, int b, int c) {
        cout << "���ǹ��캯��2�������� " << endl;
        m_a_ = a;
        m_b_ = b;
        m_c_ = c;
    }
    ~fruit() {
        cout << "�������������������� " << endl;
    }
public:
    void init(int a_, int b_, int c_); //��Ա����������ˮ���ۼۣ�����������ԭ�ۡ�
    int price(); //��Ա������ ��ˮ���ܼ�
    int dollar(); //��Ա������������ˮ���������
private:
    int m_a_;
    int m_b_;
    int m_c_; //��Ա����,ˮ���ۼۣ�����������ԭ��
}; //�ⲿ����һ����Ķ���

void fruit::init(int a, int b, int c)
{
    m_a_ = a;
    m_b_ = b;
    m_c_ = c;
}

int fruit::price()
{
    return m_a_ * m_b_;
}//��Ա�����Ķ���

int fruit::dollar()
{
    return (m_a_ - m_c_) * m_b_;
}//��Ա�����Ķ���

int main()
{
    int a, b, c;
    fruit r;  //r��һ������
    cin >> a >> b >> c;
    r.init(a, b, c);//ʹ����ĳ�Ա�����ͳ�Ա����
    cout << "It's price is " << r.price() << endl;
    cout << "It's dollar is " << r.dollar() << endl;
    //cout << sizeof(fruit) << endl;
    fruit r2(a, b, c); //�����˵ڶ��������
    return 0;
}