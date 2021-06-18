#include "��ͷ.h"
using namespace std;
class Sale_data
{
public:
	Sale_data() = default;
	Sale_data(string s):BookNo(s){}
	string isbn() const { return BookNo; }
private:
	string BookNo;
};
bool paraIsbn(Sale_data &a, Sale_data &b)
{
	return a.isbn() < b.isbn();
}
bool judge(const string &s)
{
	return s.size() > 5;
}
int func(int i)
{
	return 1;
}
int statistic(const string &s, int &count)
{
	if (s.size() > 6)
	{
		++count;
	}
	return count;
}
bool check_size(const string &s, size_t i)
{
	return i > s.size();
}
//string(&func(string (&arr)[10]))[10];//��ͨ����
//
//using ArrT = string[10];//���ͱ�����ʾ
//ArrT &func1(ArrT& arr);
//
//auto func2(ArrT &arr)->string(&)[10];//β�÷�������
//
//string  arrs[10];//decltype����
//decltype(arrs)& func3(ArrT& arr);

int main()
{
	//10.1��ϰ
	/*vector<int> vec{ 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 8 };
	cout<<count(vec.begin(), vec.end(),6);

	list<string> ls{ "acc","bcc","ccc","dcc","acc" };
	cout << count(ls.begin(), ls.end(),"acc");*/

	//10.2.1��ϰ
	/*vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	cout << accumulate(vec.begin() + 5, vec.end() - 2,10);*/

	//��ʼֵ�����Ǹ���������Ȼ���о�����ʧ
	/*vector<double> vec{ 1.2,3.4,5.6,7.8,9.0 };
	cout << accumulate(vec.cbegin(), vec.cend(), 0.0);*/

	//10.3.1��ϰ
	//vector<Sale_data> vec{ string("jack"), string("andrew"), string("mori"), string("kacirin") };
	//*vector<string> v{ "jack", "andrew", "mori", "kacirin" };
	//vec.assign(v.begin(), v.end());*/
	//sort(vec.begin(), vec.end(),paraIsbn);
	//for (auto x : vec)
	//{
	//	cout << x.isbn() << ' ';
	//}

	//10.3.2��ϰ
	//auto f = [](int i, int j) {return i + j; };
	/*int a;
	auto f = [a](int b) {cout << a + b; };*/

	/*vector<Sale_data> vec{ string("jack"), string("andrew"), string("mori"), string("kacirin") };
	sort(vec.begin(), vec.end(), [](const Sale_data &a, const Sale_data &b) {return a.isbn() < b.isbn(); });*/

	/*vector<string> v{ "jack", "andrew", "mori", "kacirin" };
	int sz = 5;
	auto x = stable_partition(v.begin(), v.end(), [sz](const string &s1) {return s1.size() >= 5; });//stable_partition(),���ֺ��ֵ�������
	auto it = v.begin();
	for (it; it != x; ++it)
	{
		cout << *it << ' ';
	}*/

	//10.3.3��ϰ
	//��׼��count_if()��������¼ν��Ϊ�����������ؼ���
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	cout << count_if(word.begin(), word.end(), [](const string &s) {return s.size() > 6; });*/
	//��i=0,���ڵݼ�
	/*int i = 5;
	auto f = [&i]()->bool {if (i == 0)return true;--i;return false;};
	int j;
	do
	{
		j = f();
		cout << j << endl;
	} while (j != 1);*/

	//10.3.4��ϰ
	//vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	//int count = 0;
	////bind()�а����õĲ�������ʹ��ref������cref����,statistic�����е�count�����ã����Ա���ʹ��ref����Ȼ�޷�����
	//for_each(word.begin(), word.end(), bind(statistic, placeholders::_1, ref(count)));
	//cout << count << endl;
	
	//��vector�в��ҵ�һ������s���ȵ�ֵ
	/*string s = "beauty";
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	auto x=find_if(vec.begin(), vec.end(), bind(check_size,ref(s),placeholders::_1));
	cout << *x << endl;*/

	//bind����lambda��дpartition
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	auto it=partition(word.begin(), word.end(), bind(check_size, placeholders::_1, 6));
	for (auto x = word.begin();x != it; ++x)
	{
		cout << *x << ' ';
	}*/

	//10.4.2��ϰ
	//fstream out("C++.txt");//�����ļ�
	//string s;
	//out.open("C++.txt" ,ios::out|ios::app);
	/*for (int i = 0; i < 5; ++i)
	{
		getline(cin, s);
		out << s.c_str() << endl;
	}*/
	/*vector<string> vec;
	istream_iterator<string> in_iter(out), eof;

	copy(in_iter, eof, back_inserter(vec));    //��һ�ֹ���vec��������vector<int> vec(in, eof);

	for_each(vec.begin(), vec.end(), [](const string &s) {cout << s << endl; });
	out.close();*/

	/*istream_iterator<int> in(cin), eof;
	vector<int> vec(in, eof);
	sort(vec.begin(), vec.end(), [](int i, int j) {return i < j; });
	ostream_iterator<int> out(cout, " ");
	copy(vec.begin(), vec.end(), out); */

    //unique_copy��ӡ���ظ���ֵ
    //vector<int> vec{ 1,2,3,4,5,5,5,6,6,6,7,8,9 };
    //ostream_iterator<int> out(cout, " ");
    //unique_copy(vec.begin(), vec.end(), out);

    //fstream in;
    //in.open("1.txt", ios::out)
    //istream_iterator<int> it(cin), end;
    //vector<int> vec(it, end);
    //for_each(vec.begin(), vec.end(), [&in](int i) {in << i << ' '; });
    //fstream out("2.txt");
    //fstream out2("3.txt");
    //ostream_iterator<int> it2(out, "\n");
    //ostream_iterator<int> it3(out2, "\n");
    //for_each(vec.begin(), vec.end(), [&it2, &it3](int &i) {if (i % 2 == 0) it2++ = i; else it3++ = i; });
}