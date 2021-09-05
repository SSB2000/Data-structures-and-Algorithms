//CTCI 1.6: String Compression: Implement a method to perform basic string compression using the counts of repeated characters.For example, the string aabcccccaaa would become a2blc5a3.If the "compressed" string would not become smaller than the original string, your method should return the original string.You can assume the string has only uppercase and lowercase letters(a - z).

#include <iostream>
#include <string>

using namespace std;

string stringCompression(const string str)
{
	string newStr = "";
	int i = 0;
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		count++;
		if (i + 1 >= str.length() || str[i] != str[i + 1])
		{
			newStr.push_back(str[i]);
			char countChar = count + '0';
			newStr.push_back(countChar);
			count = 0;
		}
	}
	return (newStr.length() < str.length()) ? newStr : str;
}

int main()
{
	cout << stringCompression("aabcccccaa") << '\n';
	return 0;
}