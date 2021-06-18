#include<iostream>
#include "附加.h"
#define end "none"
using namespace std;
int main()
{
	//11.1.4统计单词个数
	/*map<string, size_t> word_count;
	string s;
	while (getline(cin, s))
	{
		for_each(s.begin(), s.end(), [](char &c) {c = tolower(c); });
		s.erase(remove_if(s.begin(), s.end(), ispunct), s.end());
		++word_count[s];
	}
	for (auto x : word_count)
	{
		cout << x.first << ":" << x.second << endl;
	}*/



	//11.2.1统计家庭的姓和孩子
	/*map<string, vector<string>> family;
	string first_name, child_name;
	while (1)
	{
		cout << "请输入家庭的姓:";
		cin >> first_name;
		if (first_name == "end")
		{
			break;
		}
		cout << "请输入孩子名字:" << endl;
		while (getline(cin, child_name) && child_name != "end")
		{
			family[first_name].push_back(child_name);
		}
	}
	for (const auto &i : family)
	{
		cout << "家庭名为" << i.first << "有以下成员:" << endl;
		for (const auto j : i.second)
		{
			cout << j << ' ';
		}
		cout << endl;
	}*/



	//11.2.2统计单词出现行数
	//map<string, list<size_t>> sad;
	//string s;
	//int i = 1;
	//map<string, list<size_t>>::iterator it = sad.begin();
	//while (getline(cin, s))
	//{
	//	sad[s].push_back(i);//单独sad[s]就可以记录所有关键字
	//	++i;
	//}
	//for (auto x : sad)
	//{
	//	cout << x.first;
	//	for (auto y : x.second)
	//	{
	//		cout << y << ' ';
	//	}
	//	cout << endl;
	//}

	//11.2.3 pair类型的vector
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


    //11.2.3使用vector<pair>类型的map,pair保存孩子名和生日
    /*map<string, vector<pair<string,string>>> family;
	string first_name, child_name, child_birth;
	
	while (1)
	{
		cout << "请输入家庭的姓:";
		cin >> first_name;
		if (first_name == end)
		{
			break;
		}
		cout << "请输入孩子的姓名:";
		while (cin>>child_name&&child_name!=end)
		{
			cout << "请输入孩子的生日:";
			cin >> child_birth;
			family[first_name].push_back({ child_name,child_birth });
			cout << "请输入孩子的姓名:";
		}
	}
	cout << endl;
	for (const auto &i : family)
	{
		cout << "家庭名为" << i.first << "有以下成员:" << endl;
		for (const auto &j : i.second)
		{
			cout << j.first << ' ';
			cout << "生日:" << j.second << endl;
		}
		cout << endl;
	}*/


    //11.3.2  使用insert的bool进行单词计数，更方便
    /*map<string, size_t> mapi;
    string s;
	while (cin >> s)
	{
		auto ret = mapi.insert({ s,1 });
		if (!ret.second)
		{
			++ret.first->second;
		}
	}*/

	/*while (mapi.find(author) != mapi.end())
	{
		mapi.erase(mapi.find(author));
	}
    for (auto x : mapi)
	{
	    cout << x.first << ' ' << x.second << endl;
	{*/
}