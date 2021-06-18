#include "БъЭЗ.h"
using namespace std;
vector<int>::iterator find(vector<int>::iterator it1, vector<int>::iterator it2, int val)
{
	while (it1!=it2)
	{
		if (*it1 == val)
		{
			return it1;
		}
		++it1;
	}
	return it2;
}
int main()
{
	array<int, 5> arr(5);
	for (auto x : array)
	{
		cout << x << ' ';
	}
}