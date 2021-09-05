#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
	vector<int> ways(amount + 1, 0);
	ways[0] = 1;
	for(int coin : coins)
	{
		for(int am = 1; am < amount + 1; ++am)
		{
			if(coin <= am)
			{
				ways[am] += ways[am - coin];
			}
		}
	}
	for(int i = 0; i < ways.size(); ++i)
	{
		cout << ways[i] << ' ';
	}
	cout << endl;
	return ways[amount];
}

int main() 
{
	vector<int> i = {1, 5, 10, 25};
	cout << change(10, i) << '\n';
}
