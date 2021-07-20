#include "headfile.h"
using namespace std;
class A
{
public:
	A() = default;
	A(int i) :x(i) { cout << "调用构造函数" << endl; }
	A &operator =(const A &rhs){
		cout << "调用赋值运算符" << endl;
		x = rhs.x;
		return *this;
	}
private:
	int x;
};
int main()
{
	A a(10);
	A b;
	b = a;//区别何时调用拷贝构造函数和赋值运算符是看有没有新的对象产生
}