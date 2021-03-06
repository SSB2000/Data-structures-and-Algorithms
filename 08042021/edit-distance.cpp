#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2)
{
	int dp[str1.length() + 1][str2.length() + 1];
	for(int r = 0; r <= str1.length(); ++r)
	{
		dp[r][0] = r;
	}
	for(int c = 0; c <= str2.length(); ++c)
	{
		dp[0][c] = c;
	}
	for(int r = 1; r <= str1.length(); ++r)
	{
		for(int c = 1; c <= str2.length(); ++c)
		{
			if (str1[r - 1] == str2[c - 1])
			{
				dp[r][c] = dp[r - 1][c - 1]; 
			}	
			else 
			{
				dp[r][c] = 1 + min(dp[r - 1][c], min(dp[r - 1][c - 1], dp[r][c - 1]));
			}
		}
	}
	return dp[str1.length()][str2.length()];
}

int main()
{
	string str1 = "abc";
	string str2 = "yabd";
	cout << editDistance(str1, str2) << endl;
}
