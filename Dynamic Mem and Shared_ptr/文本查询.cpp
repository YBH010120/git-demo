#include "headfile.h"
using namespace std;
class QueryResult;
class TextQuery
{
public:
	TextQuery(ifstream &is);
	QueryResult query(const string &s) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<vector<string>::size_type>>> wm;
};
TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is,text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line>>word)
		{
			auto &line = wm[word];
			if (!line)
				line.reset(new set<vector<string>::size_type>);
			line->insert(n);
		}
	}
}
class QueryResult
{
	friend ostream &print(ostream &, const QueryResult);
public:
	QueryResult(string s, shared_ptr<set<vector<string>::size_type>> p, shared_ptr<vector<string>> file);
private:
	string result;
	shared_ptr<set<vector<string>::size_type>> line;
	shared_ptr <vector<string>> file;
};
int main()
{

}