#include <iostream>
using namespace std;
class fruit
{
public:
    int a,b,c; //��Ա����,ˮ���ۼۣ�����������ԭ��
    void init(int a_, int b_,int c_); //��Ա����������ˮ���ۼۣ�����������ԭ�ۡ�
    int price(); //��Ա������ ��ˮ���ܼ�
    int dollar(); //��Ա������������ˮ���������
}; //�ⲿ����һ����Ķ���
void fruit::init(int a_, int b_,int c_)
{
    a = a_;  b = b_; c = c_;
}
int fruit::price()
{
    return a*b;
}//��Ա�����Ķ���
int fruit::dollar()
{
    return (a-c)*b;
}//��Ա�����Ķ���
int main()
{
    int a,b,c;
    fruit a;  //a��һ������
    cin >> a>> b>>c;
    r.init(a,b,c);//ʹ����ĳ�Ա�����ͳ�Ա����
    cout << "It's price is " << a.price() << endl;
    cout << "It's dollar is " << a.dollar();
    cout << sizeof(fruit) << endl;
    return 0;
}