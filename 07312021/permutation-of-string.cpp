//Design an algorithm to print all permutations of a string. For simplicity, assume all characters are unique.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> permutation_STL(string s)
{
	sort(s.begin(), s.end());
	vector<string> res;
	do
	{
		res.push_back(s);
	} while (next_permutation(s.begin(), s.end()));

	return res;
}

vector<string> permutation_recursion(string s)
{

	if (s.length() == 1)
		return;
}

int main()
{
	string s;
	s = "abc";

	vector<string> res;
	// res  = permutation_STL(s);
	res = permutation_recursion(s);

	for (string s : res)
		cout << s << ' ';

	cout << '\n';
}