#include "headfile.h"
using namespace std;
class HasPtr
{
public:
	HasPtr(const string &s = string()):ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &HP) : ps(new string(*(HP.ps))), i(HP.i) { cout << "���ÿ������캯��" << endl; }
	HasPtr& operator =(const HasPtr &rhs)
	{
		cout << "���ÿ�����ֵ�����" << endl;
		i = rhs.i;
		string *p = new string(*(rhs.ps));
		delete ps;
		ps = p;
		return *this;
	}
	const string& getStr1()//����string������
	{
		return *ps;
	}
	const string* getStr2()//����ָ��ps��ָ��
	{
		return ps;
	}
	const int getInt()
	{
		return i;
	}
private:
	string *ps;
	int i;
};
int main()
{
	HasPtr a("hello world");
	HasPtr b=a;//�൱��b(a),���ÿ������캯��
	HasPtr c;
	c = a;//����=��
	
}