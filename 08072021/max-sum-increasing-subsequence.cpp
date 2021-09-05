#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr(10, INT_MIN);
	for (auto nu : arr)
	{
		cout << nu << ' ';
	}
}

