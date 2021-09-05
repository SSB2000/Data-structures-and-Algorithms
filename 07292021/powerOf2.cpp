// Print power of 2s inside a given number

#include <iostream>

using namespace std;

int powerOf2(int num)
{
	if (num < 0)
		return 0;
	else if (num == 1)
	{
		cout << 1 << ' ';
		return 1;
	}
	else
	{
		int prev = powerOf2(num / 2);
		int curr = prev * 2;
		cout << curr << ' ';
		return curr;
	}
}

int main()
{
	powerOf2(10);
	return 0;
}