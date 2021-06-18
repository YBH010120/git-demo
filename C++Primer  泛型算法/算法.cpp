#include "��ͷ.h"
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
void biggies(vector<string> &words, ostream &os = cout, char c = ' ')//IO�����ܿ�����ֻ�ܴ�����
{
	for_each(words.begin(), words.end(), [&, c](const string &s) {os << s << c; });//��ϲ���ʽ
	for_each(words.begin(), words.end(), [=, &os](const string &s) {os << s << c; });//��һ�ֻ�ϲ���
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
	//10.2.1�ʼ�
	//vector<string> vec;
	//string num = accumulate(vec.begin(), vec.end(), ""); ""��const char*,û�ж���+�����
	//string num = accumulate(vec.begin(), vec.end(), string(""));

	//equal�㷨�÷�,���ԱȽ�������ͬ�������͵������е�Ԫ�أ���Ҫ��ڶ������������һ������һ����
	/*vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	list<int> lis{ 2,3,4,5,6,7,8 ,10,10};
	cout << equal(vec.begin() + 1, vec.end() , lis.begin());*/


	//10.2.2�ʼ�
	//vector<int> vec(10);
	//fill(vec.begin(), vec.begin() + vec.size() / 2, 5);//˫����������Ԫ�ظ����������Χ�ڵľ�Ԫ��
	//fill_n(vec.begin(), 11, 10);//��������������Ԫ�ظ�����������ʼ��n��Ԫ�أ�n���ܳ���

	//ɾ����ͬ�ַ�unique��ǰ���������ַ�����������ͬ��Ԫ�ض��ǰ��ŵ�
	/*vector<string> vec{ "b","a","a","b" };
	sort(vec.begin(), vec.end());
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());*/

	//10.3.1
	//stable_sort()���Ա��ֵȳ�Ԫ�ؼ���ֵ���
	//vector<string> vec{ "the","quick","red","fox","jumps","over","the","slow","red","turtle" };
	////elimDups(vec);
	//sort(vec.begin(), vec.end());
	//stable_sort(vec.begin(), vec.end(), isShorter);
	//for (const auto &x : vec)
	//{
	//	cout << x << ' ';
	//}
	//cout << endl;
	//paratition�÷�������ν�ʶ����ݽ��л��֣�ν��Ϊtrue��������ǰ�벿�֣��������ں��棬����һ��ָ�����һ��Ϊtrue��Ԫ�ص���һ��λ��
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	auto iter2=partition(word.begin(), word.end(), judge);
	auto iter1 = word.begin();
	for (iter1; iter1 != iter2; ++iter1)
	{
		cout << *iter1 << ' ';
	}
	cout << endl;*/

	//10.3.2  lambda���ʽ
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	stable_sort(word.begin(), word.end(), [](const string &s1, const string &s2){return s1.size() < s2.size(); });
	auto wc = find_if(word.begin(), word.end(), [sz=(size_t)5](const string &s) {return s.size() >= sz; });
	auto count = word.end() - wc;
	for_each(wc, word.end(), [](const string &s) {cout << s << ' '; });*/

	//ֵ����
	//size_t v1 = 42;
	//auto f = [v1]() {return v1; };
	////����ֵ����lambda���ܸı���ֵ�����Ǽ���mutable
	//auto f1 = [v1]() mutable{++v1; return v1; };
	//�����������Ͳ���Ҫmutable
	//auto f2 = [&v1]() {++v1; return v1; };
	//vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	//for_each(word.begin(), word.end(), [c = ' '](const string &s){cout << s << c; });
	//biggies(word);

	//ֱ�Ӷ�������в�����ʱ�������Ҫ������
	/*array<int,10> a = { 0,1,2,3,4,5,6,7,8,9};
	for_each(a.begin(), a.end(), [](int &i) {++i; cout << i << ' '; });*/

	//transform()�㷨
	//array<int, 9> a = { -1,2,-3,4,-5,6,-7,8,-9 };
	//vector<int> vec;
	//list<int> l2, l3;
	//vec.assign(a.begin(), a.end());
	//for_each(vec.begin(), vec.end(), [](int &i) {cout << i<<' '; });
	//cout << endl;
	//transform(vec.begin(), vec.end(), back_inserter(l2), negate<int>());//vec��Ԫ�س�-1Ȼ���L2;
	//for_each(l2.begin(), l2.end(), [](int &i) {cout << i << ' '; });
	//cout << endl;
	//transform(l2.begin(), l2.end(), l2.begin(), bind2nd(multiplies<int>(), 10));//L2��Ԫ�ء�10��
	//for_each(l2.begin(), l2.end(), [](int &i) {cout << i << ' '; });
	//cout << endl;
	////������������ǵȼ۵�������䣬��ô���->(return type)
	//transform(vec.begin(), vec.end(), vec.begin(), [](int i)->int {if (i < 0) return -i; else return i; });//vec������С��0����ȡ����ֵ
	//for_each(vec.begin(), vec.end(), [](int &i) {cout << i << ' '; });
	//cout << endl;

	//��׼��count_if()��������¼ν��Ϊ�����������ؼ���
	/*vector<string> word{ "beautiful", "odds", "true", "antify", "unstopped", "oar" };
	cout << count_if(word.begin(), word.end(), [](const string &s) {return s.size() > 6; });*/

	//bind���滻lambda
	//vector<string> word{ "beautiful", "true", "odds", "antify", "unstopped", "oar" };
	//lambdaд��
	//int sz = 6;
	//auto f1 = find_if(word.begin(), word.end(), [sz](const string &s){s.size() > sz; });
	////bindд��������Ҫ���������¶���һ������
	//auto f2 = find_if(word.begin(), word.end(), bind(check_size, placeholders::_1, sz));

	//bind���Ų���˳��
	/*stable_sort(word.begin(), word.end(), isShorter);
	for_each(word.begin(), word.end(), [](const string &s) {cout << s << ' '; });
	cout << endl;
	stable_sort(word.begin(), word.end(), bind(isShorter, placeholders::_2, placeholders::_1));
	for_each(word.begin(), word.end(), [](const string &s) {cout << s << ' '; });
	cout << endl;
*/
	//��׼��ref����
	//lambda���ʽд��
	//ostream &os = cout; char c = ' ';
	//for_each(word.begin(),word.end(), [&os, c](const string &s) {os << s << c; });
	//bindд��
	//for_each(word.begin(), word.end(), bind(print, ref(os), placeholders::_1, ' '));

	//list<int> lst = { 1,2,3,4};
	//auto it = inserter(lst, lst.begin());
	//list<int> lst2, lst3;
	////back_inserter���������
	//copy(lst.cbegin(), lst.cend(), back_inserter(lst2));
	//for_each(lst2.begin(), lst2.end(), [](int i) {cout << i << ' '; });
	//cout << endl;
	//lst2.clear();
	////front_inserter���������
	//copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
	//for_each(lst2.begin(), lst2.end(), [](int i) {cout << i << ' '; });
	//cout << endl;
	////inserter���������������Ĳ���
	//copy(lst.begin(), lst.end(), inserter(lst3, lst3.begin()));
	//for_each(lst3.begin(), lst3.end(), [](int i) {cout << i << ' '; });
	//cout << endl;

	//unique_copy�㷨
	/*vector<int> vec{ 1,2,2,3,4,5,5,6,7,8,8,8,9 };
	list<int> lst;
	unique_copy(vec.begin(), vec.end(), inserter(lst, lst.begin()));
	for_each(lst.begin(), lst.end(), [](int i) {cout << i << ' '; });
	cout << endl;*/

    //���ֲ��������
	//vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
	//list<int> lis1, lis2, lis3;
	///*copy(vec.begin(), vec.end(), back_inserter(lis1));
	//for_each(lis1.begin(), lis1.end(), [](int i) {cout << i << ' '; });
	//cout << endl;*/
	//copy(vec.rbegin(), vec.rend(), front_inserter(lis1));
	//for_each(lis1.begin(), lis1.end(), [](int i) {cout << i << ' '; });
	//cout << endl;
 
    //iostream������
    /*istream_iterator<int> in_iter(cin);
	istream_iterator<int> eof;*/
	/*while (in_iter!=eof)
	{
		vec.push_back(*in_iter++);
	}*/
	//���õ�д��
	//vector<int> vec(in_iter,eof);
	//for_each(vec.begin(), vec.end(), [](int i) {cout << i<<' '; });

	//ʹ���㷨������������
	//cout << accumulate(in_iter, eof, 0);

    //ʹ��ostream_iterator��ӡ
    //istream_iterator<int> in_iter(cin), eof;
	//vector<int> vec(in_iter, eof);
	//ostream_iterator<int> out_iter(cout," ");
	////��ͨ������ӡvecֵ�������ò�������++����ʡ��
	///*for (auto x : vec)
	//{
	//	out_iter= x;
	//}*/
	////ʹ��ν�ʱ��ʽ����ӡvecֵ
	//copy(vec.begin(), vec.end(), out_iter);
	//cout << endl;
	//for_each(vec.begin(), vec.end(), out_iter);//����ı�ʾ
   
    //merge����
    /*vector<int> vec{ 1,2,3,4,5 };
	vector<int> v{ 0,1,2,3,4 };
	vector<int> it;
	merge(vec.begin(), vec.end(), v.begin(), v.end(),back_inserter(it));
	for (auto x : it)
	{
		cout << x << ' ';
	}*/
}