#include "headfile.h"
using namespace std;
class A
{
public:
	A() = default;
	A(int i) :x(i) { cout << "���ù��캯��" << endl; }
	A &operator =(const A &rhs){
		cout << "���ø�ֵ�����" << endl;
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
	b = a;//�����ʱ���ÿ������캯���͸�ֵ������ǿ���û���µĶ������
}