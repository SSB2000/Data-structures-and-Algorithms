// A child is running up a staircase with n steps and can hop either  1  step, 2 steps, or 3 
// steps at a time. Implement a method to count how many possible ways the child can run up the stairs. 

#include <iostream>
#include <unordered_map>
using namespace std;
int noOfWays(int n,unordered_map<int, int>& memo)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (memo.find(n) != memo.end())
		return memo[n];
	int count = 0;
	for(int i = 1; i < 4; ++i)
		count += noOfWays(n - i, memo);
	memo[n] = count;
	return memo[n];
}
int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> memo;
	cout << noOfWays(n, memo);
}
