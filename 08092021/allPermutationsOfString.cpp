#include <iostream>
#include <string>
#include <vector>
using namespace std;

void getAll(string s, int ind, int len, vector<string>& res)
{
	if(ind == len - 1)
	{
		//cout << s << ' ';
		res.push_back(s);
		return;
	}
	for(int i = ind; i < len; ++i)
	{
		string tempstr = s;
		char temp = tempstr[ind];
		tempstr[ind] = tempstr[i];
		tempstr[i] = temp;
		//cout << tempstr << ' ' << i << ' ' << ind << '\n';
		getAll(tempstr, ind + 1, len, res);
	}
}

int main()
{
	string s = "aajsfdljherghljsfliasjfliwjeflasijfalisjfliasjflasidjfliwejf";
	vector<string> res;
	getAll(s, 0, s.size(), res);
	for(string str : res)
		cout << str << ' ';
	cout << endl;
}
