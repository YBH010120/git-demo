#include "附加.h"
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
	//统计单词个数
	/*map<string, size_t> word_count;
	set<string> exclude{ "the","but","and","or","an","a" };
	string word;
	while (cin>>word)
	{
		if (exclude.find(word) == exclude.end())//如果find的返回的迭代器的为end，则说明没找到
		{
			++word_count[word];
		}
	}
	for (auto x : word_count)
	{
		cout << x.first << " occur " << x.second << " time " << endl;
	}*/



	//统计单词出现行数
	//map<string, list<size_t>> sad;
	//string s;
	//int i = 1;
	//map<string, list<size_t>>::iterator it = sad.begin();
	//while (getline(cin,s))
	//{
	//	sad[s].push_back(i);//单独sad[s]就可以记录所有关键字
	//	++i;
	//}
	//for (auto x : sad)//遍历时要看清关键字的值是什么类型
	//{
	//	cout << x.first;
	//	for (auto y : x.second)
	//	{
	//		cout << y << ' ';
	//	}
	//	cout << endl;
	//}




	//vector可以定义关键字为迭代器类型的，因为定义了迭代器比较大小，list则不行
	/*map<vector<int>::iterator, int> mp1;
	map<list<int>::iterator, int> mp2;
	vector<int> vec{ 9,8,7,6,5,4,3,2,1 };
	vector<int>::iterator it=vec.begin();
	while (it != vec.end())
	{
		++mp1[it];
	}*/





	//pair类型用法，nubility
	//vector<pair<string, int>> b;
	 
	//pair<string, int> a;//第一种创建的方法
	/*while (cin >> a.first >> a.second)
	{
		b.push_back(a);
	}*/

	//string s;//第二种创建的方法
	//int a;
	//while (cin>>s>>a)
	//{
	//	b.push_back(make_pair(s, a));//简便方法，make_pair会根据给定的元素类型返回一个pair类型的结果，用于初始化vector
	//}

	//string s;//第三种创建的方法,类似于第二种
	//int a;
	//while (cin>>s>>a)
	//{
	//	b.push_back({ s,a });
	//}


	//for (auto it : b)
	//{
	//	cout << it.first << ' ' << it.second << endl;
	//}

	//sort(b.begin(), b.end());//pair类型的元素也可以排序哦
	//for (auto it : b)
	//{
	//	cout << it.first << ' ' << it.second << endl;
	//}

	
	//set关键字只读性，map关键字只读性，值可写性
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
		++map_it->second;//可以改变第二元素的值
	}*/
    


    //关于关联容器使用插入迭代器
    /*multiset<string> m={ "jack","jim","jason","jock","jack","jim" };
	vector<string> v{"tom","lucy"};*/
	/*copy(v.begin(), v.end(), inserter(m,m.end()));
	for_each(m.begin(), m.end(), [](const string &s) {cout << s << ' '; });*/

	//copy(v.begin(), v.end(),m);//不合法
	//for_each(m.begin(), m.end(), [](const string &s) {cout << s << ' '; });

	/*copy(m.begin(), m.end(), inserter(v,v.end()));
	for_each(v.begin(), v.end(), [](const string &s) {cout << s << ' '; });*/

	/*copy(m.begin(), m.end(), back_inserter(v));
	for_each(v.begin(), v.end(), [](const string &s) {cout << s << ' '; });*/


     //map的insert操作
     //map<string, size_t> word_count;
	 //string word;
	 //while (cin>>word)
	 //{
		// auto ret = word_count.insert({ word,1 });//ret的类型为pair<map<string,size_t>::iterator,bool>
		// if (!ret.second)
		// {
		//	 ++ret.first->second;
		// }
	 //}
	 //for (auto x : word_count)
	 //{
		// cout << x.first << ":" << x.second << endl;
	 //}
     

    
     //map的下标操作
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
	 //map<string, size_t>::key_type it;//对map进行下标操作
	 //map<string, size_t>::mapped_type;//进行下标操作的返回值类型
	 //it = "lucy";
	 //cout << mapi[it];


     //multimap查找同一关键字的所有值
	/*multimap<string, string> mapi{ {"jack","love"},{"jack","you"}};
	string author = "jack";*/
	   //auto entries = mapi.count(author);//第一种查找方式
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
	//for (; beg != end; ++beg)//第二种查找值的方式
	//   {
	//	   cout << beg->second << endl;
	//   }

	   /*for (auto pos = mapi.equal_range(author); pos.first != pos.second; ++pos.first)//第三种查找值的方式，equal_range返回两个迭代器
	   {
		   cout << pos.first->second << endl;
	   }*/
	

     //单词转换
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