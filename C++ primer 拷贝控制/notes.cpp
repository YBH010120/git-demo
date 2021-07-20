#include "headfile.h"
using namespace std;
class HasPtr
{
public:
	HasPtr(const string &s = string()):ps(new string(s)), i(0) {}
	HasPtr(const HasPtr &HP) : ps(new string(*(HP.ps))), i(HP.i) { cout << "调用拷贝构造函数" << endl; }
	HasPtr& operator =(const HasPtr &rhs)
	{
		cout << "调用拷贝赋值运算符" << endl;
		i = rhs.i;
		string *p = new string(*(rhs.ps));
		delete ps;
		ps = p;
		return *this;
	}
	const string& getStr1()//返回string的引用
	{
		return *ps;
	}
	const string* getStr2()//返回指向ps的指针
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
	HasPtr b=a;//相当于b(a),调用拷贝构造函数
	HasPtr c;
	c = a;//调用=；
	
}