#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Tabulation
// T.C = O(M^2*N)     S.C O(M)
bool canConstructTable(string targetString, vector<string> &wordBank)
{
	if (targetString == "")
		return true;
	vector<bool> table(targetString.size() + 1, false);
	table[0] = true;
	for (int i = 0; i <= targetString.length(); i++)
	{
		if (table[i] == true)
		{
			for (string word : wordBank)
			{
				if (targetString.substr(i, word.length()) == word)
				{
					table[i + word.length()] = true;
				}
			}
		}
	}
	return table[targetString.length()];
}
bool canConstructMemo(string targetString, vector<string> &wordBank, map<string, bool> &memo)
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
			if (canConstructMemo(suffixToFind, wordBank, memo))
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
	cout << canConstructMemo(string1, wordBank1, memo) << '\n';
	cout << canConstructTable(string1, wordBank1) << '\n';

	wordBank1 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	string1 = "skateboard";
	cout << canConstructMemo(string1, wordBank1, memo) << '\n';
	cout << canConstructTable(string1, wordBank1) << '\n';

	wordBank1 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	string1 = "enterapotentpot";
	cout << canConstructMemo(string1, wordBank1, memo) << '\n';
	cout << canConstructTable(string1, wordBank1) << '\n';

	wordBank1 = {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeee"};
	string1 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
	cout << canConstructMemo(string1, wordBank1, memo) << '\n';
	cout << canConstructTable(string1, wordBank1) << '\n';

	return 0;
}