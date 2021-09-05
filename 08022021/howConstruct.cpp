#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Tabulation
// T.C = O(M^2*N)     S.C O(M)
int canConstructTable(string targetString, vector<string> &wordBank)
{
	if (targetString == "")
		return true;
	vector<int> table(targetString.size() + 1, 0);
	table[0] = 1;
	for (int i = 0; i <= targetString.length(); i++)
	{
		for (string word : wordBank)
		{
			if (targetString.substr(i, word.length()) == word)
			{
				table[i + word.length()] = table[i + word.length()] + table[i];
			}
		}
	}
	return table[targetString.length()];
}

int main()
{
	vector<string> wordBank1 = {"ab", "abc", "cd", "def", "abcd", "ef"};
	string string1 = "abcdef";
	cout << canConstructTable(string1, wordBank1) << '\n';

	wordBank1 = {"bo", "rd", "ate", "t", "ska", "sk", "boar"};
	string1 = "skateboard";
	cout << canConstructTable(string1, wordBank1) << '\n';

	wordBank1 = {"a", "p", "ent", "enter", "ot", "o", "t"};
	string1 = "enterapotentpot";
	cout << canConstructTable(string1, wordBank1) << '\n';

	wordBank1 = {"e", "ee", "eee", "eeee", "eeeeee", "eeeeeeee"};
	string1 = "eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef";
	cout << canConstructTable(string1, wordBank1) << '\n';

	return 0;
}