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
	cout << il.size();//il���ж��ٸ�����
}

class StrBolbPtr;
class StrBolb
{
public:
	friend class StrBolbPtr;
	StrBolbPtr begin();
	StrBolbPtr end();
public:
	typedef vector<string>::size_type size_type;
	StrBolb();
	StrBolb(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string &t) { data->push_back(t); }
	void pop_back();
	size_t getMaxsize() { return data->size(); }
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

class StrBolbPtr
{
public:
	StrBolbPtr() :curr(0) {}
	StrBolbPtr(StrBolb &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	string &deref() const;
	StrBolbPtr &incr();
	size_t getSize() { return curr; }
private:
	shared_ptr<vector<string>> check(size_t, const string &) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;
};
shared_ptr<vector<string>> StrBolbPtr::check(size_t i, const string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound StrBolbPtr");
	if (i > ret->size())
		throw out_of_range(msg);
	return ret;
}
string& StrBolbPtr::deref() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}
StrBolbPtr& StrBolbPtr::incr()
{
	check(curr, "increment past end of StrBolbPtr");
	++curr;
	return *this;
}
StrBolbPtr StrBolb::begin() { return StrBolbPtr(*this); }
StrBolbPtr StrBolb::end(){	return StrBolbPtr(*this, data->size());}

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
	//shared_ptr��ɾ����
	//shared_ptr<connection> p(&c, [](connection *p) {disconnect(*p); });
	//cout << "connecting now(" << p.use_count() << ")" << endl;*/

	//unique_ptr��ɾ����
	unique_ptr<connection, decltype(end_connection) *> p(&c, end_connection);
}
int main()
{
	//�쳣�׳�����
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
	

	//����ָ�����
	//auto p = make_shared<int>(10);
	//auto r = make_shared<int>(42);
	//auto q(r);
	//cout << r.use_count() <<' '<< q.use_count() <<' '<< p.use_count() << endl;
	//r = p;
	//cout << r.use_count() << ' ' <<q.use_count()<<' '<< p.use_count() << endl;//��Ϊr��q���󶨵���42�������߼�������Ϊ2,��ֻ��q��10���ʼ�����Ϊ1
	//q = p;
	//cout << r.use_count() << ' ' << q.use_count() << ' ' << p.use_count() << endl;//����ȫ�󶨵�10��������Ϊ3


	//error_msg({1,2,3,4,5});//initialize_listʹ��

	//�������ֲ������b2��sizeΪ0
	/*StrBolb b1;
	{
		StrBolb b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b1.size() << ' ' << b2.size() << endl;
	}
	cout << b1.size()<< endl;*/


	//ָ��int��vector���͵�shared_ptr
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


	//auto p = new auto(string("sss"));//ʹ��new auto����ʼ��������ֻ�ܸ���һ��
	//int *a = new int;
	//const int *b = new const int;//��̬�����const�����ʼ��


	//д��Ƿ�ף�����falseҲ�����ǿ�ָ������ڴ�ռ�ľ�
	/*int *p2 = new int();
	if (p2 == NULL)
	{
		return false;
	}*/

	//ʹ���쳣����,bad_allocĬ��Ϊ���ڴ�ռ䲻���׳����쳣��������ͷ�ļ�new��
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
			<< "������" << i*4 << "M" << endl;
	}*/

	//�������쳣Ҳ����ʹ��nothrow
	//int *p4 = new(nothrow) int;//�ڴ�ռ䲻��ʱ���ؿ�ָ��
	//if (p4 == NULL)
	//{
	//	return false;
	//}

	
	//�α���ϰ12.6
	//auto p = func();
	//cout << p << endl;//��ʼָ���ַ
	//func2(p);
	//print(p);
	//delete p;
	//p = nullptr;//ɾ����ָ���ַָ���㣬����ָ��
	//cout << p << endl;
 
    //ʹ������ָ����д����
      /*auto q = shared_ptr_func();
	  func3(q);
	  print(q);*/

      //int *q = new int(5);
	  //shared_ptr<int> p(q);//����ʹ��ֱ�ӳ�ʼ����ʽ����Ϊ����ָ�����������ָ�빹�캯����explicit��
	  //cout << p.use_count();


  //shared_ptr��new���ʹ��
  //   shared_ptr<int> p = make_shared<int>(42);
	 //auto f = [](shared_ptr<int> p) {return p.use_count(); };//��ֵ���ݣ�����2�������ô����򷵻�1��
	 //cout << f(p);
	 //cout << p.use_count();//��������������Ϊ1��
	 //int *x(new int(1024));
	 //cout << *x << endl;//��֮��ָ��ָ���ֵ���жԱ�
	 //auto f1 = [](shared_ptr<int> p) { };
	 //f1(shared_ptr<int>(x));
	 //cout << *x;//��ʱx����ָ���Ѿ��ͷŵ��ڴ棬���һ������ָ�룬ָ���ֵ��δ�����
  //   shared_ptr<int> p(new int(42));
	 //int *q = p.get();
	 //{
		// shared_ptr<int> x(q);
	 //}//�����������ʱ��x�ͷ��ڴ棬p��Ϊ����ָ��
	 //int foo = *p;

     //auto sp = make_shared<int>();//
     //auto p = sp.get();
     //delete p;//���ͷ�pָ����ڴ��spҲ���ͷţ���ɶ���delete�����ִ���
     
      /*destination des("A");
	  f(des);*/
      
      /*int a = 10;//a��ջ�ڴ棬���������ʱ���Զ��ͷ�
	  int *x = &a;
	  {
		  shared_ptr<int> p(x);
		  
	  }*///����ָ���ͷ�xָ����ڴ棬����a�Ѿ��Զ��ͷţ���ɶ���delete



      
	  //auto p2(p1);��֧�ֿ���
	  //auto p3=p2;��֧�ָ�ֵ
	  //shared_ptr֧�ֿ����͸�ֵ����
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
	  ////��Ȼ���ܿ����͸�ֵ�������Ե���release��reset
	  //unique_ptr<MyClass> p2(p1.release());//p1��������Ȩ������ָ��
	  //if (!p1)
		 // cout << "p1  not exist" << endl;
	  //unique_ptr<MyClass> p3(new MyClass("B"));
	  //p2.reset(p3.release());
	  //if (p2)
		 // cout << "p2 exist" << endl;
	  //if (!p3)
		 // cout << "p3 not exist" << endl;
	  //������
	     // A created ����ָ�����Ͷ��󣬲���p1ָ��
		 // p1  not exist  p1��������Ȩ��p2ָ��ԭ��A�ĵ�ַ
		 // B created    ����ָ�����Ͷ��󣬲���p3ָ��
		 // destroyed    p3��������Ȩ������p3��������
		 // p2 exist     p2�ӹ�p3ԭ��ָ��Ķ����ַ
		 // p3 not exist   p3������
		 // destroyed    ������p1����������

	  
	  /*shared_ptr<int> sp=make_shared<int>(10);
	  shared_ptr<int> sp1(sp);
	  weak_ptr<int> p1(sp);
	  weak_ptr<int> p2 = sp;*/
	  //cout << sp.use_count() << endl;//������ı�shared_ptr�ļ���
	  //cout << p1.use_count() << endl;//��weak_ptr���������ָ�������
	  //sp.reset();
	  //sp1.reset();
	  //cout << p1.expired() << endl;//������Ϊ0���򷵻�1
	  //����ʹ��*�����ֱ�ӷ���weak_ptrָ��Ķ�����Ϊ������ܲ�����
	  //if (shared_ptr<int> np = p1.lock());//expireΪfalseʱ��lock����һ��ָ������shared_ptr����֤���ʰ�ȫ��


	  //12.20��ϰ
	  /*string name = "StrBolb.txt";
	  fstream in(name, ios::in);
	  string temp;
	  StrBolb a;
	  while (getline(in,temp))
	  {
		  a.push_back(temp);
	  }
	  for (StrBolbPtr p(a.begin());p.getSize()!=a.getMaxsize(); p.incr())
	  {
		  cout << p.deref() << endl;
	  }*/
	  
	  //shared_ptrû�ж����±��������ʹ��get��������ָ����з���
	  /*shared_ptr<int> sp(new int[10], [](int *p) {delete[]p; });
	  for (int i = 0; i < 10; ++i)
		  cout << *(sp.get() + i) << ' ';*/

	  //��ϰ12.23
	 // const char *s1 = "hello,";
	 // const char *s2 = "world";
	 // char *sp = new char[strlen(s1)+strlen(s2)+1];
	  //strcpy_s(sp,strlen(s1)+1,s1);//��Ҫ����Դ�ַ����Ĵ�С(����'\0')
	  //strcat_s(sp,strlen(s2)+strlen(sp)+1,s2);//��Ҫ���ڶ���������Դ�ַ���׷�ӵ�Ŀ���ַ����󻺳������ܴ�С
	  //cout << sp;
	  //����string
	  /*string s1 = "hello,", s2 = "world";
	  char *p = new char[s1.size()+s2.size()+1];
	  strcpy_s(p,s1.size()+s2.size()+1,(s1 + s2).c_str());
	  cout << p;*/
	  //��̬����������
	  /*string a;
	  cin >> a;
	  char *p = new char[a.size()+1];
	  strcpy_s(p,a.size()+1,a.c_str());
	  cout << p << endl;
	  delete[]p;*/
}