#include "headfile.h"
using namespace std;
void point1()//reset的用法
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
	a.reset();//没有可选参数，a被置为空
	//a.reset(b)//a释放之前的内存，指向b
	if (!a)
		cout << "shared_ptr is not exist" << endl;

}
void point2()//vector的resize机理
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
	//unique_ptr<string> p2(p1);//不支持拷贝
		//unique_ptr<string> p3=p2;//不支持赋值
	  //shared_ptr支持拷贝和赋值操作
	  shared_ptr<int> s1(new int(5));
	  auto s2(s1);
	  auto s3 = s1;

	//release不会返回指针，但不会释放内存，只有reset可以释放
	  p1.release();//不释放内存，且丢失指针
	  auto p2 = p1.release();
	  delete p2;//需要手动delete
	  p1.reset();//reset

}
void point4()//weaker_ptr必须指向shared_ptr
{
	shared_ptr<int> sp(new int(10));
	shared_ptr<int> sp1(sp);
	weak_ptr<int> p1(sp);
	weak_ptr<int> p2 = sp;
	cout << sp.use_count() << endl;//并不会改变shared_ptr的计数
	cout << p1.use_count() << endl;
	//sp.reset();
	//sp1.reset();
	//cout << p1.expired() << endl;//若计数为0，则返回1
	//不能使用*运算符直接访问weak_ptr指向的对象，因为对象可能不存在
	if (shared_ptr<int> np = p1.lock());//expire为false时，lock返回一个指向对象的shared_ptr；保证访问安全性
}
int main()
{
	point3();
}