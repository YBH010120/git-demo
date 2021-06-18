#include "标头.h"
using namespace std;
void myfunction(int i) {  // function:
	cout << i << ' ';
}
void myfunction2(string i) {  // function:
	cout << i << ' ';
}
void find(forward_list<string> &lis, string s1, string s2)
{
	auto x = lis.before_begin();
	auto y = lis.begin();
	bool flag = false;
	for (y; y != lis.end(); ++y, ++x)
	{
		if (*y == s1)
		{
			lis.insert_after(y, s2);
			flag = true;
		}
	}
	if (!flag)
	{
		lis.insert_after(x, s2);
	}
}
void func(string &s, string oldVal, string newVal)
{
	//insert和erase使用迭代器形式，要使用advance函数
	/*string::iterator x = s.begin();
	string::iterator it1 = newVal.begin();
	string::iterator it2 = newVal.end();
	int oldsize = oldVal.size();
	int newsize = newVal.size();
	for (x;x<=(s.end()-oldVal.size()+1);++x)
	{
		if (s.substr(x - s.begin(), oldsize) == oldVal)
		{
			x = s.erase(x, x + oldsize);
			s.insert(x, it1, it2);
			advance(x, newsize - 1);
		}
	}*/
	//下面是replace和下标形式
	int oldsize = oldVal.size();
	int newsize = newVal.size();
	for (int i = 0; i < s.size() - oldsize; ++i)
	{
		if (s.substr(i, oldsize) == oldVal)
		{
			s.replace(i, oldsize, newVal);
			i += newsize - 1;
		}
	}
}
void find(string numbers, string s)//分别找到字符和数字
{
	string::size_type pos = 0;
	while ((pos = numbers.find_first_of(s, pos)) != string::npos)
	{
		cout << "在第" << pos + 1 << "个位置找到数字" << numbers[pos] << endl;
		++pos;
	}
	pos = 0;
	while ((pos = numbers.find_first_not_of(s, pos)) != string::npos)
	{
		cout << "在第" << pos + 1 << "个位置找到英文字母" << numbers[pos] << endl;
		++pos;
	}
}
class date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;
public:
	date() = default;
	date(string s)
	{
		
	}
};
int main()
{
	//使用反向容器,forward_list不支持
	/*list<int> lis;
	list<int>::reverse_iterator it;
	for (int i = 0; i < 10; ++i)
	{
		lis.push_back(i);
	}
	for (it = lis.rbegin(); it != lis.rend(); ++it)
	{
		cout << *it << ' ';
	}*/

	//链表可以在头和尾插入
	/*list<int> lis;
	list<int>::iterator it;
	for (int i = 0; i < 10; ++i)
	{
		lis.push_front(i);
		lis.push_back(i);
	}
	for (it = lis.begin(); it != lis.end(); ++it)
	{
		cout << *it << ' ';
	}*/

	//Copy函数 ForEach用法
	/*vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(7);
	vector<int> v2;
	v2.resize(vec.size());
	copy(vec.begin(), vec.end(), v2.begin());
	vector<int>::iterator it;
	for_each(v2.begin(), v2.end(), myfunction);*/

	//replace函数
	/*vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(3);
	replace(vec.begin(), vec.end(), 3, 300);
	for_each(vec.begin(), vec.end(), myfunction);*/

	//accumulate函数
	/*vector<int> vec;
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(3);
	cout<<accumulate(vec.begin(), vec.end(), 10);*/

	//容器直接拷贝和迭代器范围拷贝
	/*vector<const int> vec;
	for (int i = 0; i < 10; ++i)
	{
		vec.push_back(i);
	}
	vector<const int> const v(vec);
	vector<const int>::const_iterator it1 = v.begin(), it2 = v.end();
	list<int> lis(it1,it2);
	for (auto x : lis)
	{
		cout << x << ' ';
	}*/

	//insert函数
	/*用法1:在指定位置it前“插入”值为val的元素,返回指向这个元素的迭代器,
	iterator insert(iterator it, const TYPE &val);

	用法2:在指定位置it前“插入”num个值为val的元素 
	void insert(iterator it, size_type num, const TYPE &val);

	用法3:在指定位置it前“插入”区间[start, end)的所有元素. 
	void insert(iterator it, input_iterator start, input_iterator end);

	举例:
	创建一个vector,置入字母表的前十个字符 
	vector <char> charV;
	for (int i = 0; i < 10; i++)
		charV.push_back(i + 65);

	插入四个C到vector中 
	vector <char>::iterator it = charV.begin();
	charV.insert(it, 4, 'C');

	显示vector的内容 
	for (it = charV.begin(); it != charV.end(); it++)
		cout << *it;*/

		//测试各个容器的swap速度，list>vector>array
		/*list<int> lis1;
		list<int> lis2;
		vector<int> vec1;
		vector<int> vec2;
		for (int i = 0; i < 1000; ++i)
		{
			lis1.push_back(i);
			vec1.push_back(i);
		}
		using namespace std::literals::chrono_literals;
		auto start = chrono::high_resolution_clock::now();
		swap(lis2,lis1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<float> duration = end - start;
		cout << duration.count() << "s" << endl;

		auto start1 = chrono::high_resolution_clock::now();
		swap(vec2, vec1);
		auto end1 = chrono::high_resolution_clock::now();
		chrono::duration<float> duration1 = end1 - start1;
		cout << duration1.count() << "s" << endl;*/

		//erase用法
	/*int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> vec;
	list<int> lis(ia, ia + 11);
	auto it1 = lis.begin();
	while (it1 != lis.end())
	{
		if (*it1 % 2 != 0)
		{
			vec.push_back(*it1);
			it1 = lis.erase(it1);
		}
		else
		{
			++it1;
		}
	}
	for_each(lis.begin(), lis.end(), myfunction);
	cout << endl;
	for_each(vec.begin(), vec.end(), myfunction);*/

	//forward_list的erase操作
//forward_list<int> flis = { 1,3,5,7,8,9 };
//auto prev = flis.before_begin();
//auto curr = flis.begin();
//while (curr!=flis.end())
//{
//	if (*curr % 2)
//	{
//		curr = flis.erase_after(prev);
//		for_each(flis.begin(), flis.end(), myfunction);
//		cout << endl;
//	}
//	else
//	{
//		prev = curr;
//		++curr;
//	}
//}

	//resize用法，如果新大小小于原大小，则resize(n.t)=resize(n)
	/*vector<int> vec(25, 1);
	vec.resize(100, 2);
	for_each(vec.begin(), vec.end(), myfunction);
	cout << endl;
	vec.resize(10,3);
	for_each(vec.begin(), vec.end(), myfunction);
	cout << endl;*/

	//vector如何增长以及何时重新分配内存
	/*vector<int> vec;
	vec.reserve(1024);
	for (int i = 0; i < 684; ++i)
	{
		vec.push_back(i);
	}
	vec.resize(vec.size() + vec.size() / 2);
	cout << vec.capacity() << endl;*/

    //stack计算表达式
    /*stack<char> st;
	string expr("(1+2)+(3+4)+5");
	int sum = 0;
	int len = expr.size();
	for (int i = 0; i < len; ++i)
	{
		if (expr[i] == '(' || isdigit(expr[i]))
		{
			st.push(expr[i]);
		}
		else if ((expr[i] == '+'))
		{
			continue;
		}
		else if (expr[i] == ')')
		{
			while (st.top()!='(')
			{
				sum += st.top() - '0';
				st.pop();
			}
			st.pop();
		}
	}
	while (!st.empty())
	{
		sum += st.top() - '0';
		st.pop();
	}
	cout << sum;*/

string s1 = "eeffefaadwdslakdjk";
string s2 = "aa";
auto x = s1.find(s2);
cout << x;
}