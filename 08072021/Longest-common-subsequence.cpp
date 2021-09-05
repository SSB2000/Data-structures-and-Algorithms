// 1143. Longest Common Subsequence
// Given two strings text1 and text2, return the length of their longest common subsequence.If there is no common subsequence, return 0.

// 	A subsequence of a string is a new string generated from the original string with some
// 	characters(can be none) deleted without changing the relative order of the remaining characters.

// 	For example,
// 	"ace" is a subsequence of "abcde".

// 	A common subsequence of two strings is a subsequence that is common to both strings.

void printdp(vector<vector<int>> &dp, int sl1, int sl2)
{
	for (int i = 0; i < sl1 + 1; ++i)
	{
		for (int j = 0; j < sl2 + 1; ++j)
		{
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}
int longestCommonSubsequence(string text1, string text2)
{
	int sl1 = text1.length();
	int sl2 = text2.length();
	vector<vector<int>> dp(sl1 + 1, vector<int>(sl2 + 1, 0));
	for (int i = 1; i < sl1 + 1; ++i)
	{
		for (int j = 1; j < sl2 + 1; ++j)
		{
			if (text1[i - 1] == text2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
			}
		}
	}
	return dp[sl1][sl2];
}