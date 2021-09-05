#include <string>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

string sortSentence(string s)
{
	stringstream ss(s);
	string res = "";
	map<int, string> pos;
	string word;
	while (ss >> word)
	{
		pos[word[word.length() - 1] - '0'] = word.substr(word.length() - 1);
	}
	for (auto it : pos)
	{
		res = res + " " + it.second;
	}
	return res;
}

int main()
{
	cout << sortSentence("is2 sentence4 This1 a3");
	return 0;
}

class Solution
{
public:
	string sortSentence(string s)
	{

		int i = 0, c = 0;
		int a = 0;
		int k = 0;
		int n = s.size();
		string s1 = "";
		for (int i = 0; i < n; i++)
		{
			if (s[i] == ' ')
				c++;
		}
		vector<string> s2(c + 1);

		for (i = 0; i < n; i++)
		{
			if (s[i] == ' ')
			{
				a = s[i - 1] - 49;

				s2[a] = s.substr(k, i - 1);
				k = i + 1;
			}
		}

		for (int i = 0; i < c; i++)
		{
			s1 = s1 + s2[i] + " ";
			cout << s1 << endl;
		}
		s1 = s1 + s2[c];

		return s1;
	}
};