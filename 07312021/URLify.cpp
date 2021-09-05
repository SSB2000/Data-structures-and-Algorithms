// Write a method to replace all spaces in a string with '%20'. You may assume that the  string
// has sufficient space at the end  to  hold the additional characters,  and that you are given the "true" length  of  the  string.
// CTCI 1.3

#include <iostream>
#include <string>
using namespace std;

int numOfSpace(const string &s1, const int &tlen)
{
	int count = 0;
	for (int i = 0; i < tlen; i++)
	{
		if (s1[i] == ' ')
			count++;
	}
	return count;
}

string URLify(const string &str)
{
	const int tlen = str.length();
	const int spaceNum = numOfSpace(str, tlen);
	const int resizedLength = tlen + spaceNum * 2; // As 1 space is already counted
	int index = resizedLength - 1;
	string res(resizedLength, '0');
	for (int i = tlen - 1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			cout << i << '\n';
			res[index] = '0';
			res[index - 1] = '2';
			res[index - 2] = '%';
			index = index - 3;
		}
		else
		{
			res[index] = str[i];
			index--;
		}
	}

	return res;
}

int main()
{
	string str = "My name is Shubham";
	str = URLify(str);
	cout << str << '\n';

	return 0;
}