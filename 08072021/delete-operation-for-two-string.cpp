// 583. Delete Operation for Two Strings

// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
// In one step, you can delete exactly one character in either string.

void printdp(vector<vector<int>> &dp)
{
	for (int i = 0; i < dp.size(); ++i)
	{
		for (int j = 0; j < dp[0].size(); ++j)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}
int minDistance(string word1, string word2)
{
	int wl1 = word1.length();
	int wl2 = word2.length();
	vector<vector<int>> dp(wl1 + 1, vector<int>(wl2 + 1, 0));
	for (int i = 0; i < wl1 + 1; ++i)
		dp[i][0] = i;
	for (int j = 0; j < wl2 + 1; ++j)
		dp[0][j] = j;
	for (int i = 1; i < wl1 + 1; ++i)
	{
		for (int j = 1; j < wl2 + 1; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	// printdp(dp);
	return dp[wl1][wl2];
}