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

int *q = new int(5);
	  shared_ptr<int> p(q);
	  delete q;
	  p = NULL;
	  cout << p.use_count();
}