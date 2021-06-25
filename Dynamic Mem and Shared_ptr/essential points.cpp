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
void point4()//weaker_ptr����ָ��shared_ptr
{
	shared_ptr<int> sp(new int(10));
	shared_ptr<int> sp1(sp);
	weak_ptr<int> p1(sp);
	weak_ptr<int> p2 = sp;
	cout << sp.use_count() << endl;//������ı�shared_ptr�ļ���
	cout << p1.use_count() << endl;
	//sp.reset();
	//sp1.reset();
	//cout << p1.expired() << endl;//������Ϊ0���򷵻�1
	//����ʹ��*�����ֱ�ӷ���weak_ptrָ��Ķ�����Ϊ������ܲ�����
	if (shared_ptr<int> np = p1.lock());//expireΪfalseʱ��lock����һ��ָ������shared_ptr����֤���ʰ�ȫ��
}
int main()
{
	point3();
}