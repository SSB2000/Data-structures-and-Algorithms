//CTCI: 1.5:  One Away: There  are  three  types  of  edits  that  can be  performed  on  strings:  insert  a  character, remove a character, or  replace a character. Given  two strings, write a  function to check if they are one edit (or zero edits) away.

#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
using namespace std;

bool oneAway(string ss1, string ss2)
{
	// Using bitset
	// cheching how many character difference does the 2 string have
	// Wrong approach
	bitset<26> alp;
	for (char ch : ss1)
		alp.flip(ch - 'a');
	for (char ch : ss2)
		alp.flip(ch - 'a');

	return alp.count() < 3;
}

bool oneAwayBrute(string ss1, string ss2)
{
	sort(ss1.begin(), ss1.end());
	sort(ss2.begin(), ss2.end());
	if (ss1 == ss2)
		return true;
}

int main()
{
	string ss1 = "abcdefghijk";
	string ss2 = "abcdefghk";
	cout << oneAwayBrute(ss1, ss2) << '\n';

	return 0;
}
