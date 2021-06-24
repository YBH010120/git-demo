#include "headfile.h"
using namespace std;
void point1()//reset���÷�
{
	struct A
	{
		int i;
		A() { cout << "construct\n" << endl; }
		~A() { cout << "delete " << i << endl; }
	};
	shared_ptr<A> a(new A);
	A* b = new A;
	a->i = 1;
	b->i = 2;
	a.reset();//û�п�ѡ������a����Ϊ��
	//a.reset(b)//a�ͷ�֮ǰ���ڴ棬ָ��b
	if (!a)
		cout << "shared_ptr is not exist" << endl;

}
void point2()//vector��resize����
{
	class A
	{
	public:
		A() { cout << "created" << endl; }
		~A() { cout << "destroy" << endl; }
	};
	vector<A> vec;
	vec.resize(5);
}
void point3()//unique_ptr
{
	unique_ptr<string> p1(new string("A"));
	//unique_ptr<string> p2(p1);//��֧�ֿ���
		//unique_ptr<string> p3=p2;//��֧�ָ�ֵ
	  //shared_ptr֧�ֿ����͸�ֵ����
	  shared_ptr<int> s1(new int(5));
	  auto s2(s1);
	  auto s3 = s1;

	//release���᷵��ָ�룬�������ͷ��ڴ棬ֻ��reset�����ͷ�
	  p1.release();//���ͷ��ڴ棬�Ҷ�ʧָ��
	  auto p2 = p1.release();
	  delete p2;//��Ҫ�ֶ�delete
	  p1.reset();//reset

}
int main()
{
	point3();
}