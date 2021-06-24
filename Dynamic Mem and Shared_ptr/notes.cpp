#include "headfile.h"
using namespace std;
void my_stdexcept(double a,double b)
{
	if (b==0) {
		throw std::runtime_error("input error!");
	}
	else {
		printf("%lf",a/b);
	}
}
int init()
{
	shared_ptr<int> sp2 = make_shared<int>(2);
	shared_ptr<int> sp3(sp2);
	cout << sp2.use_count() << endl;
	return sp2.use_count();
}
void error_msg(initializer_list<int> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
	{
		cout << *beg << ' ';
	}
	cout << endl;
	cout << il.size();//il中有多少个参数
}
class StrBolb
{
public:
	typedef vector<string>::size_type size_type;
	StrBolb();
	StrBolb(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	/*string &front() const;
	string &back() const ;*/
private:
	shared_ptr<vector<string>> data;
	bool check(size_type i, const string &msg) const;
};
StrBolb::StrBolb() :data(make_shared<vector<string>>()) {}
StrBolb::StrBolb(initializer_list<string> il):data(make_shared<vector<string>>(il)){}
bool StrBolb::check(size_type i, const string &msg) const
{
	try
	{
		if (i >= data->size())
		{
			throw out_of_range(msg);
		}
	}
	catch (const out_of_range &err)
	{
		cout << err.what() << endl;
		return true;
	}
	return false;
}
//string &StrBolb::front() const
//{
//	if (check(0, "front on empty StrBolb"))
//	{
//
//	}
//	else
//	return data->front();
//}
//string &StrBolb::back() const
//{
//	if (check(0, "back on empty StrBolb"))
//	{
//
//	}
//	else
//	return data->back();
//}
void StrBolb::pop_back()
{
	check(0, "pop_back on empty StrBolb");
	data->pop_back();
}
vector<int> *func()
{
	return new vector<int>;
}
shared_ptr<vector<int>> shared_ptr_func()
{
	shared_ptr<vector<int>> vec(new vector<int>);
	return vec;
}
void func3(shared_ptr<vector<int>> ptr)
{
	int val;
	while (cin>>val)
	{
		ptr->push_back(val);
	}
}
void print(shared_ptr<vector<int>> ptr)
{
	for (auto x : *ptr)
	{
		cout << x << ' ';
	}
}
void func2(vector<int> *vec)
{
	int i;
	while (cin>>i)
	{
		vec->push_back(i);
	}
}
void print(vector<int> *p)
{
	for (const auto &i : (*p))
	{
		cout << i << ' ';
	}
	cout << endl;
}
shared_ptr<int> clone(int p)
{
	return shared_ptr<int>(new int(p));
}
struct destination {
	string des;
	destination(string des_) :des(des_) {}
};
struct connection {
	string conn;
	connection(string conn_) :conn(conn_) {}
};
connection connect(destination *des_)
{
	cout << "connect to " << des_->des << endl;
	return connection(des_->des);
}
void disconnect(connection conn_)
{
	cout << "disconnect " << conn_.conn << endl;
}
void end_connection(connection *p) { disconnect(*p); }
void f(destination &d)
{
	connection c = connect(&d);
	//shared_ptr的删除器
	//shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p); });
	//cout << "connecting now(" << p.use_count() << ")" << endl;*/

	//unique_ptr的删除器
	unique_ptr<connection, decltype(end_connection) *> p(&c, end_connection);
}
int main()
{
	//异常抛出处理
	/*double a, b;
	while (cin>>a>>b)
	{
		try
		{
			my_stdexcept(a, b);
		}
		catch (runtime_error err)
		{
			cout << err.what();
			cout << "need to input again? enter y or n:" << endl;
			char c;
			cin >> c;
			if (!cin || c == 'n')
			{
				break;
			}
		}
	}*/
	

	//智能指针计数
	//auto p = make_shared<int>(10);
	//auto r = make_shared<int>(42);
	//auto q(r);
	//cout << r.use_count() <<' '<< q.use_count() <<' '<< p.use_count() << endl;
	//r = p;
	//cout << r.use_count() << ' ' <<q.use_count()<<' '<< p.use_count() << endl;//因为r和q都绑定倒了42，故两者计数器都为2,而只有q绑定10，故计数器为1
	//q = p;
	//cout << r.use_count() << ' ' << q.use_count() << ' ' << p.use_count() << endl;//三者全绑定到10，计数器为3


	//error_msg({1,2,3,4,5});//initialize_list使用

	//在跳出局部程序后，b2的size为0
	/*StrBolb b1;
	{
		StrBolb b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b1.size() << ' ' << b2.size() << endl;
	}
	cout << b1.size()<< endl;*/


	//指向int的vector类型的shared_ptr
	/*auto ptr = make_shared<vector<int>>();
	for (int i = 1; i <= 10; ++i)
	{
		ptr->push_back(i);
	}
	auto x = ptr->begin();
	for (x; x != ptr->end(); ++x)
	{
		cout << *x << ' ';
	}*/


	//auto p = new auto(string("sss"));//使用new auto，初始化括号里只能给出一项
	//int *a = new int;
	//const int *b = new const int;//动态分配的const必须初始化


	//写法欠妥，返回false也可能是空指针而非内存空间耗尽
	/*int *p2 = new int();
	if (p2 == NULL)
	{
		return false;
	}*/

	//使用异常处理,bad_alloc默认为当内存空间不足抛出的异常，定义在头文件new中
	/*int *p3 = NULL;
	int i = 0;
	try {
		do
		{
			p3 = new int[1024 * 1024];
			++i;
		} while (p3);
	}
	catch(bad_alloc &e){
		cout << e.what() << "\n"
			<< "分配了" << i*4 << "M" << endl;
	}*/

	//避免抛异常也可以使用nothrow
	//int *p4 = new(nothrow) int;//内存空间不足时返回空指针
	//if (p4 == NULL)
	//{
	//	return false;
	//}

	
	//课本练习12.6
	//auto p = func();
	//cout << p << endl;//初始指针地址
	//func2(p);
	//print(p);
	//delete p;
	//p = nullptr;//删除后指针地址指向零，即空指针
	//cout << p << endl;
 
    //使用智能指针重写上题
      /*auto q = shared_ptr_func();
	  func3(q);
	  print(q);*/

      //int *q = new int(5);
	  //shared_ptr<int> p(q);//必须使用直接初始化形式，因为接受指针参数的智能指针构造函数是explicit的
	  //cout << p.use_count();


  //shared_ptr和new结合使用
  //   shared_ptr<int> p = make_shared<int>(42);
	 //auto f = [](shared_ptr<int> p) {return p.use_count(); };//以值传递，返回2；以引用传递则返回1；
	 //cout << f(p);
	 //cout << p.use_count();//跳出函数块后计数为1；
	 //int *x(new int(1024));
	 //cout << *x << endl;//与之后指针指向的值进行对比
	 //auto f1 = [](shared_ptr<int> p) { };
	 //f1(shared_ptr<int>(x));
	 //cout << *x;//此时x继续指向已经释放的内存，变成一个空悬指针，指向的值是未定义的
  //   shared_ptr<int> p(new int(42));
	 //int *q = p.get();
	 //{
		// shared_ptr<int> x(q);
	 //}//当跳出程序块时，x释放内存，p成为空悬指针
	 //int foo = *p;

     //auto sp = make_shared<int>();//
     //auto p = sp.get();
     //delete p;//当释放p指向的内存后，sp也会释放，造成二次delete，出现错误
     
      /*destination des("A");
	  f(des);*/
      
      /*int a = 10;//a是栈内存，当程序结束时，自动释放
	  int *x = &a;
	  {
		  shared_ptr<int> p(x);
		  
	  }*///智能指针释放x指向的内存，但因a已经自动释放，造成二次delete



      
	  //auto p2(p1);不支持拷贝
	  //auto p3=p2;不支持赋值
	  //shared_ptr支持拷贝和赋值操作
	  /*shared_ptr<int> s1(new int(5));
	  auto s2(s1);
	  auto s3 = s1;*/

      int x;
	  //class MyClass
	  //{
	  //public:
		 // MyClass(string s) { cout <<s<<' '<< "created"<<endl; };
		 // ~MyClass() { cout << "destroyed"<<endl; };
	  //private:
		 // string s;
	  //};
	  //unique_ptr<MyClass> p1(new MyClass("A"));
	  ////虽然不能拷贝和赋值，但可以调用release和reset
	  //unique_ptr<MyClass> p2(p1.release());//p1放弃控制权并返回指针
	  //if (!p1)
		 // cout << "p1  not exist" << endl;
	  //unique_ptr<MyClass> p3(new MyClass("B"));
	  //p2.reset(p3.release());
	  //if (p2)
		 // cout << "p2 exist" << endl;
	  //if (!p3)
		 // cout << "p3 not exist" << endl;
	  //输出结果
	     // A created 创建指针类型对象，并由p1指向
		 // p1  not exist  p1放弃控制权，p2指向原来A的地址
		 // B created    创建指针类型对象，并由p3指向
		 // destroyed    p3放弃控制权，调用p3析构函数
		 // p2 exist     p2接管p3原来指向的对象地址
		 // p3 not exist   p3不存在
		 // destroyed    最后调用p1的析构函数

	  

	  
}