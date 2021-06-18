#include "����.h"
#include<iostream>
using namespace std;
#define eof "none"
map<string, string> buildMap(ifstream &map_file);
const string &transform(const string &s, const map<string, string> &m);
void word_transformation(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input,text))
	{
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream>>word)
		{
			if (firstword)
			{
				firstword = false;
			}
			else
			{
				cout << " ";
			}
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}
map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string value;
	while (map_file >> key && getline(map_file, value))
	{
		if (value.size() > 1)
		{
			trans_map[key] = value.substr(1);
		}
	}
	return trans_map;
}
const string &transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	if (map_it != m.cend())
	{
		return map_it->second;
	}
    return s;
}
int main()
{
	//ͳ�Ƶ��ʸ���
	/*map<string, size_t> word_count;
	set<string> exclude{ "the","but","and","or","an","a" };
	string word;
	while (cin>>word)
	{
		if (exclude.find(word) == exclude.end())//���find�ķ��صĵ�������Ϊend����˵��û�ҵ�
		{
			++word_count[word];
		}
	}
	for (auto x : word_count)
	{
		cout << x.first << " occur " << x.second << " time " << endl;
	}*/



	//ͳ�Ƶ��ʳ�������
	//map<string, list<size_t>> sad;
	//string s;
	//int i = 1;
	//map<string, list<size_t>>::iterator it = sad.begin();
	//while (getline(cin,s))
	//{
	//	sad[s].push_back(i);//����sad[s]�Ϳ��Լ�¼���йؼ���
	//	++i;
	//}
	//for (auto x : sad)//����ʱҪ����ؼ��ֵ�ֵ��ʲô����
	//{
	//	cout << x.first;
	//	for (auto y : x.second)
	//	{
	//		cout << y << ' ';
	//	}
	//	cout << endl;
	//}




	//vector���Զ���ؼ���Ϊ���������͵ģ���Ϊ�����˵������Ƚϴ�С��list����
	/*map<vector<int>::iterator, int> mp1;
	map<list<int>::iterator, int> mp2;
	vector<int> vec{ 9,8,7,6,5,4,3,2,1 };
	vector<int>::iterator it=vec.begin();
	while (it != vec.end())
	{
		++mp1[it];
	}*/





	//pair�����÷���nubility
	//vector<pair<string, int>> b;
	 
	//pair<string, int> a;//��һ�ִ����ķ���
	/*while (cin >> a.first >> a.second)
	{
		b.push_back(a);
	}*/

	//string s;//�ڶ��ִ����ķ���
	//int a;
	//while (cin>>s>>a)
	//{
	//	b.push_back(make_pair(s, a));//��㷽����make_pair����ݸ�����Ԫ�����ͷ���һ��pair���͵Ľ�������ڳ�ʼ��vector
	//}

	//string s;//�����ִ����ķ���,�����ڵڶ���
	//int a;
	//while (cin>>s>>a)
	//{
	//	b.push_back({ s,a });
	//}


	//for (auto it : b)
	//{
	//	cout << it.first << ' ' << it.second << endl;
	//}

	//sort(b.begin(), b.end());//pair���͵�Ԫ��Ҳ��������Ŷ
	//for (auto it : b)
	//{
	//	cout << it.first << ' ' << it.second << endl;
	//}

	
	//set�ؼ���ֻ���ԣ�map�ؼ���ֻ���ԣ�ֵ��д��
	/*set<int> a{ 1,2,3,4,5,6 };
	map<string, int> m{ {"jack",3} };
	set<int>::iterator set_it = a.begin();
	if (set_it != a.end())
	{
		*set_it = 42;
	}
	auto map_it = m.begin();
	while (map_it != m.end())
	{
		map_it->first = "lucy";
		++map_it->second;//���Ըı�ڶ�Ԫ�ص�ֵ
	}*/
    


    //���ڹ�������ʹ�ò��������
    /*multiset<string> m={ "jack","jim","jason","jock","jack","jim" };
	vector<string> v{"tom","lucy"};*/
	/*copy(v.begin(), v.end(), inserter(m,m.end()));
	for_each(m.begin(), m.end(), [](const string &s) {cout << s << ' '; });*/

	//copy(v.begin(), v.end(),m);//���Ϸ�
	//for_each(m.begin(), m.end(), [](const string &s) {cout << s << ' '; });

	/*copy(m.begin(), m.end(), inserter(v,v.end()));
	for_each(v.begin(), v.end(), [](const string &s) {cout << s << ' '; });*/

	/*copy(m.begin(), m.end(), back_inserter(v));
	for_each(v.begin(), v.end(), [](const string &s) {cout << s << ' '; });*/


     //map��insert����
     //map<string, size_t> word_count;
	 //string word;
	 //while (cin>>word)
	 //{
		// auto ret = word_count.insert({ word,1 });//ret������Ϊpair<map<string,size_t>::iterator,bool>
		// if (!ret.second)
		// {
		//	 ++ret.first->second;
		// }
	 //}
	 //for (auto x : word_count)
	 //{
		// cout << x.first << ":" << x.second << endl;
	 //}
     

    
     //map���±����
     //map<string, size_t> mapi;
	 //string s;
	 //while (cin>>s)
	 //{
		// auto ret = mapi.insert({ s,1 });
		// if (!ret.second)
		// {
		//	 ++ret.first->second;
		// }
	 //}
	 //map<string, size_t>::key_type it;//��map�����±����
	 //map<string, size_t>::mapped_type;//�����±�����ķ���ֵ����
	 //it = "lucy";
	 //cout << mapi[it];


     //multimap����ͬһ�ؼ��ֵ�����ֵ
	/*multimap<string, string> mapi{ {"jack","love"},{"jack","you"}};
	string author = "jack";*/
	   //auto entries = mapi.count(author);//��һ�ֲ��ҷ�ʽ
	   //auto iter = mapi.find(author);
	   //while (entries)
	   //{
		  // cout << iter->second << endl;
		  // ++iter;
		  // --entries;
	   //}

	//auto beg = mapi.lower_bound(author), end = mapi.upper_bound(author);
	//if (beg == end)
	//{
	//	cout << "No";
	//}
	//for (; beg != end; ++beg)//�ڶ��ֲ���ֵ�ķ�ʽ
	//   {
	//	   cout << beg->second << endl;
	//   }

	   /*for (auto pos = mapi.equal_range(author); pos.first != pos.second; ++pos.first)//�����ֲ���ֵ�ķ�ʽ��equal_range��������������
	   {
		   cout << pos.first->second << endl;
	   }*/
	

     //����ת��
     /*ofstream write;
	 string s;
	 write.open("map_file.txt",ios::out|ios::app);
	 while (getline(cin,s)&&s!=eof)
	 {
		 write << s << endl;
	 }
	 write.close();
	 write.open("input.txt", ios::out | ios::app);
	 while (getline(cin,s)&&s!=eof)
	 {
		 write << s << endl;
	 }*/
	 ifstream read1, read2;
	 read1.open("map_file.txt");
	 read2.open("input.txt");
	 word_transformation(read1, read2);

     
}