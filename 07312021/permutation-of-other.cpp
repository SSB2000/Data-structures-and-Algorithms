// Given two string s1 and s2 check if one permutatin of other.
// CTCI array/string 02

#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool isPermutationSort(string s1, string s2)
{
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return s1 == s2;
}

bool isPermutationMap(string s1, string s2)
{
	if (s1.length() != s2.length())
		return false;
	map<char, int> freq;
	for (int i = 0; i < s1.length(); i++)
	{
		freq[s1[i]]++;
	}
	for (int i = 0; i < s2.length(); i++)
	{
		freq[s2[i]]--;
		if (freq[s2[i]] < 0)
			return false;
	}
	return true;
}

int main()
{
	string s1 = "abcdefg";
	string s2 = "gfedcba";
	cout << isPermutationMap(s1, s2);

	return 0;
}