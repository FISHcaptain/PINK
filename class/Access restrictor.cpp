#include<iostream>
using namespace std;
class tofu {
	friend void test();//��Ԫ����������
	friend class ctest;//��Ԫ�������
public ://���ʷ�Χ˵����
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
		a.pro_fun();//��Ԫ�������Է���protected��ԱҲ���Է���private��Ա
		int z = a.pro_;//��Ԫ����Է���protected����Ҳ���Է���private����
	}
};//�ڷ���Ȩ����protected��private��һ��������Է���
int main()
{
	tofu::eat;//tofu������е�һ������
	eat.pub_;//�����Ҳ����eat���Է���public��Ա
	eat. pub_fun;//�����Ҳ���Է���public��Ա����
	return 0;
}