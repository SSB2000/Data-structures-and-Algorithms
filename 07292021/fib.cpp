// print fibonacci series till number n

#include <iostream>
#include <map>
using namespace std;

// return fib(n)
int fib(int n, map<int, long long>& memo)
{
	if (memo.find(n) != memo.end())
		return memo[n];
	if (n == 0 || n == 1)
		return n;
	memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
	return memo[n];
}

int main()
{
	map<int, long long> memo;
	for (int i = 0; i <= 50; i++)
	{
		cout << i << " : " << fib(i, memo) << '\n';
	}
	map<int, int>::iterator it;
	for (const auto& me : memo) {
		cout<<me.first<<" : "<<me.second<<'\n';
	}

	cout<<0<<'\n';
}