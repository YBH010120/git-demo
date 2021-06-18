#include "标头.h"
using namespace std;
class Sale_item
{
public:
	Sale_item() = default;
	Sale_item(string s) :BookNo(s) {}
	string isbn() const { return BookNo; }
private:
	string BookNo;
};
bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
void elimDups(vector<string> &word)
{
	sort(word.begin(), word.end());
	auto it = unique(word.begin(), word.end());
	word.erase(it, word.end());
}
void biggies(vector<string> &words, ostream &os = cout, char c = ' ')//IO流不能拷贝，只能传引用
{
	for_each(words.begin(), words.end(), [&, c](const string &s) {os << s << c; });//混合捕获方式
	for_each(words.begin(), words.end(), [=, &os](const string &s) {os << s << c; });//另一种混合捕获
}
bool check_size(const string &s, string::size_type sz)
{
	return s.size() >= sz;
}
ostream &print(ostream &os, const string &s, char c)
{
	return os << s << c;
}
int main()
{
	//10.2.1笔记
	//vector<string> vec;
	//string num = accumulate(vec.begin(), vec.end(), ""); ""是const char*,没有定义+运算符
	//string num = accumulate(vec.begin(), vec.end(), string(""));

	//equal算法用法,可以比较两个不同容器类型的容器中的元素，但要求第二个序至少与第一个序列一样长
	/*vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	list<int> lis{ 2,3,4,5,6,7,8 ,10,10};
	cout << equal(vec.begin() + 1, vec.end() , lis.begin());*/


	//10.2.2笔记
	//vector<int> vec(10);
	//fill(vec.begin(), vec.begin() + vec.size() / 2, 5);//双迭代器，新元素赋予迭代器范围内的旧元素
	//fill_n(vec.begin(), 11, 10);//单迭代器，将新元素赋给迭代器开始的n个元素，n不能超界

	//删除相同字符unique，前提是所有字符有序，所有相同的元素都是挨着的
	/*vector<string> vec{ "b","a","a","b" };
	sort(vec.begin(), vec.end());
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());*/

	//10.3.1
	//stable_sort()可以保持等长元素间的字典序
	//vector<string> vec{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	////elimDups(vec);
	//sort(vec.begin(), vec.end());
	//stable_sort(vec.begin(), vec.end(), isShorter);
	//for (const auto &x : vec)
	//{
	//	cout << x << ' ';
	//}
	//cout << endl;
	//paratition用法，接收谓词对内容进行划分，谓词为true排在容器前半部分，其余排在后面，返回一个指向最后一个为true的元素的下一个位置
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	auto iter2=partition(word.begin(), word.end(), judge);
	auto iter1 = word.begin();
	for (iter1; iter1 != iter2; ++iter1)
	{
		cout << *iter1 << ' ';
	}
	cout << endl;*/

	//10.3.2  lambda表达式
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	stable_sort(word.begin(), word.end(), [](const string &s1, const string &s2){return s1.size() < s2.size(); });
	auto wc = find_if(word.begin(), word.end(), [sz=(size_t)5](const string &s) {return s.size() >= sz; });
	auto count = word.end() - wc;
	for_each(wc, word.end(), [](const string &s) {cout << s << ' '; });*/

	//值捕获
	//size_t v1 = 42;
	//auto f = [v1]() {return v1; };
	////对于值捕获，lambda不能改变其值，除非加上mutable
	//auto f1 = [v1]() mutable{++v1; return v1; };
	//捕获引用类型不需要mutable
	//auto f2 = [&v1]() {++v1; return v1; };
	//vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	//for_each(word.begin(), word.end(), [c = ' '](const string &s){cout << s << c; });
	//biggies(word);

	//直接对数组进行操作的时候参数需要传引用
	/*array<int,10> a = { 0,1,2,3,4,5,6,7,8,9};
	for_each(a.begin(), a.end(), [](int &i) {++i; cout << i << ' '; });*/

	//transform()算法
	//array<int, 9> a = { -1,2,-3,4,-5,6,-7,8,-9 };
	//vector<int> vec;
	//list<int> l2, l3;
	//vec.assign(a.begin(), a.end());
	//for_each(vec.begin(), vec.end(), [](int &i) {cout << i<<' '; });
	//cout << endl;
	//transform(vec.begin(), vec.end(), back_inserter(l2), negate<int>());//vec中元素乘-1然后给L2;
	//for_each(l2.begin(), l2.end(), [](int &i) {cout << i << ' '; });
	//cout << endl;
	//transform(l2.begin(), l2.end(), l2.begin(), bind2nd(multiplies<int>(), 10));//L2中元素×10；
	//for_each(l2.begin(), l2.end(), [](int &i) {cout << i << ' '; });
	//cout << endl;
	////如果返回类型是等价的条件语句，最好带上->(return type)
	//transform(vec.begin(), vec.end(), vec.begin(), [](int i)->int {if (i < 0) return -i; else return i; });//vec中所有小于0的数取绝对值
	//for_each(vec.begin(), vec.end(), [](int &i) {cout << i << ' '; });
	//cout << endl;

	//标准库count_if()函数，记录谓词为真的情况，返回计数
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	cout << count_if(word.begin(), word.end(), [](const string &s) {return s.size() > 6; });*/

	//bind可替换lambda
	//vector<string> word{ "beautiful", "true", "odds", "antify", "unstopped", "oar" };
	//lambda写法
	//int sz = 6;
	//auto f1 = find_if(word.begin(), word.end(), [sz](const string &s){s.size() > sz; });
	////bind写法，可需要在外面重新定义一个函数
	//auto f2 = find_if(word.begin(), word.end(), bind(check_size, placeholders::_1, sz));

	//bind重排参数顺序
	/*stable_sort(word.begin(), word.end(), isShorter);
	for_each(word.begin(), word.end(), [](const string &s) {cout << s << ' '; });
	cout << endl;
	stable_sort(word.begin(), word.end(), bind(isShorter, placeholders::_2, placeholders::_1));
	for_each(word.begin(), word.end(), [](const string &s) {cout << s << ' '; });
	cout << endl;
*/
	//标准库ref函数
	//lambda表达式写法
	//ostream &os = cout; char c = ' ';
	//for_each(word.begin(),word.end(), [&os, c](const string &s) {os << s << c; });
	//bind写法
	//for_each(word.begin(), word.end(), bind(print, ref(os), placeholders::_1, ' '));

	//list<int> lst = { 1,2,3,4};
	//auto it = inserter(lst, lst.begin());
	//list<int> lst2, lst3;
	////back_inserter插入迭代器
	//copy(lst.cbegin(), lst.cend(), back_inserter(lst2));
	//for_each(lst2.begin(), lst2.end(), [](int i) {cout << i << ' '; });
	//cout << endl;
	//lst2.clear();
	////front_inserter插入迭代器
	//copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	//for_each(lst2.begin(), lst2.end(), [](int i) {cout << i << ' '; });
	//cout << endl;
	////inserter插入迭代器，额外的参数
	//copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
	//for_each(lst3.begin(), lst3.end(), [](int i) {cout << i << ' '; });
	//cout << endl;

	//unique_copy算法
	/*vector<int> vec{ 1,2,2,3,4,5,5,6,7,8,8,8,9 };
	list<int> lst;
	unique_copy(vec.begin(), vec.end(), inserter(lst, lst.begin()));
	for_each(lst.begin(), lst.end(), [](int i) {cout << i << ' '; });
	cout << endl;*/

    //各种插入迭代器
	//vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	//list<int> lis1, lis2, lis3;
	///*copy(vec.begin(), vec.end(), back_inserter(lis1));
	//for_each(lis1.begin(), lis1.end(), [](int i) {cout << i << ' '; });
	//cout << endl;*/
	//copy(vec.rbegin(), vec.rend(), front_inserter(lis1));
	//for_each(lis1.begin(), lis1.end(), [](int i) {cout << i << ' '; });
	//cout << endl;
 
    //iostream迭代器
    /*istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;*/
	/*while (in_iter!=eof)
	{
		vec.push_back(*in_iter++);
	}*/
	//更好的写法
	//vector<int> vec(in_iter,eof);
	//for_each(vec.begin(), vec.end(), [](int i) {cout << i<<' '; });

	//使用算法操作流迭代器
	//cout << accumulate(in_iter, eof, 0);

    //使用ostream_iterator打印
    //istream_iterator<int> in_iter(cin), eof;
	//vector<int> vec(in_iter, eof);
	//ostream_iterator<int> out_iter(cout," ");
	////普通做法打印vec值，解引用操作符和++可以省略
	///*for (auto x : vec)
	//{
	//	out_iter= x;
	//}*/
	////使用谓词表达式来打印vec值
	//copy(vec.begin(), vec.end(), out_iter);
	//cout << endl;
	//for_each(vec.begin(), vec.end(), out_iter);//错误的表示
   
    //merge函数
    /*vector<int> vec{ 1,2,3,4,5 };
	vector<int> v{ 0,1,2,3,4 };
	vector<int> it;
	merge(vec.begin(), vec.end(), v.begin(), v.end(),back_inserter(it));
	for (auto x : it)
	{
		cout << x << ' ';
	}*/
}