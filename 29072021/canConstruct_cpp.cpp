#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
bool canConstruct(string targetString, vector<string> &wordBank, map<string, bool> &memo)
{
	if (memo.find(targetString) != memo.end())
		return memo[targetString];
	if (targetString == "")
		return true;
	for (string word : wordBank)
	{
		if (targetString.find(word) == 0)
		{
			const string suffixToFind = targetString.substr(word.length());
			if (canConstruct(suffixToFind, wordBank, memo))
			{
				memo[targetString] = true;
				return memo[targetString];
			}
		}
	}
	memo[targetString] = false;
	return memo[targetString];
}

int main()
{
	map<string, bool> memo;
	vector<string> wordBank1 = {"ab", "abc", "cd", "def", "abcd"};
	string string1 = "abcdef";
	cout << canConstruct(string1, wordBank1, memo) << '\n';

	wordBank1 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	string1 = "skateboard";
	cout << canConstruct(string1, wordBank1, memo) << '\n';

	wordBank1 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	string1 = "enterapotentpot";
	cout << canConstruct(string1, wordBank1, memo) << '\n';

	wordBank1 = {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeee"};
	string1 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
	cout << canConstruct(string1, wordBank1, memo) << '\n';

	return 0;
}