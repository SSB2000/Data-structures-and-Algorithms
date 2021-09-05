// Count the number of ways it possible to construct targetString from the list of word in the wordBank
// FFC 5hr DP.

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int countConstruct(string targetString, vector<string> wordBank, map<string, int> &memo)
{
	if (memo.find(targetString) != memo.end())
		return memo[targetString];
	if (targetString == "")
		return 1;
	int totalCount = 0;

	for (string word : wordBank)
	{
		if (targetString.find(word) == 0)
		{
			int numOfWaysForRest = countConstruct(targetString.substr(word.length()), wordBank, memo);
			totalCount += numOfWaysForRest;
		}
	}

	memo[targetString] = totalCount;
	return totalCount;
}
int main()
{
	map<string, int> memo;
	cout << countConstruct("purple", {"purp", "p", "ur", "le", "purpl"}, memo) << endl;
	cout << countConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}, memo) << endl;
	cout << countConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}, memo) << endl;
	cout << countConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}, memo) << endl;
	cout << countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeeeee", "eeeeeeeee", "eeeeeeeeeeeee"}, memo);
	return 0;
}