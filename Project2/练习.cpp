#include<iostream>
#include "����.h"
#define end "none"
using namespace std;
int main()
{
	//11.1.4ͳ�Ƶ��ʸ���
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



	//11.2.1ͳ�Ƽ�ͥ���պͺ���
	/*map<string, vector<string>> family;
	string first_name, child_name;
	while (1)
	{
		cout << "�������ͥ����:";
		cin >> first_name;
		if (first_name == "end")
		{
			break;
		}
		cout << "�����뺢������:" << endl;
		while (getline(cin, child_name) && child_name != "end")
		{
			family[first_name].push_back(child_name);
		}
	}
	for (const auto &i : family)
	{
		cout << "��ͥ��Ϊ" << i.first << "�����³�Ա:" << endl;
		for (const auto j : i.second)
		{
			cout << j << ' ';
		}
		cout << endl;
	}*/



	//11.2.2ͳ�Ƶ��ʳ�������
	//map<string, list<size_t>> sad;
	//string s;
	//int i = 1;
	//map<string, list<size_t>>::iterator it = sad.begin();
	//while (getline(cin, s))
	//{
	//	sad[s].push_back(i);//����sad[s]�Ϳ��Լ�¼���йؼ���
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

	//11.2.3 pair���͵�vector
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


    //11.2.3ʹ��vector<pair>���͵�map,pair���溢����������
    /*map<string, vector<pair<string,string>>> family;
	string first_name, child_name, child_birth;
	
	while (1)
	{
		cout << "�������ͥ����:";
		cin >> first_name;
		if (first_name == end)
		{
			break;
		}
		cout << "�����뺢�ӵ�����:";
		while (cin>>child_name&&child_name!=end)
		{
			cout << "�����뺢�ӵ�����:";
			cin >> child_birth;
			family[first_name].push_back({ child_name,child_birth });
			cout << "�����뺢�ӵ�����:";
		}
	}
	cout << endl;
	for (const auto &i : family)
	{
		cout << "��ͥ��Ϊ" << i.first << "�����³�Ա:" << endl;
		for (const auto &j : i.second)
		{
			cout << j.first << ' ';
			cout << "����:" << j.second << endl;
		}
		cout << endl;
	}*/


    //11.3.2  ʹ��insert��bool���е��ʼ�����������
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