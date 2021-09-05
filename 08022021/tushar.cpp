#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	constexpr int n = 3;
	string song = "xyx ";
	int res;
	vector<int> playersOut(n, 0);
	int count = n - 1;
	int indexS = 0;
	int indexP = 0;
	int songLen = song.length();
	int playerLen = n;
	while (count > 0)
	{
		indexS = (indexS + songLen) % songLen;
		indexP = (indexP + playerLen) % playerLen;
		if (song[indexS] == 'y')
		{
			cout << indexS << '\n';
			for (int i : playersOut)
				cout << i << ' ';
			cout << '\n';
			while (playersOut[indexP] != 0)
			{
				indexP++;
				indexP = (indexP + playerLen) % playerLen;
			}
			count--;
			playersOut[indexP]++;
			indexP++;
			indexS++;
		}
		else
		{
			indexS++;
			while (playersOut[indexP] != 0)
			{
				indexP++;
				indexP = (indexP + playerLen) % playerLen;
			}
			indexP++;
		}
	}
	for (int i : playersOut)
	{
		cout << i << ' ';
	}

	return 0;
}