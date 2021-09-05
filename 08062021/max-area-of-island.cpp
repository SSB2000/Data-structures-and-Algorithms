// 695. Max Area of Island

// You are given an m x n binary matrix grid.An island is a group of 1's(representing land)connected 4 - directionally(horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid.If there is no island,
// return 0.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// DFS
int countArea(vector<vector<int>> &grid, int i, int j, unordered_set<string> &visited)
{
	bool rowInbound = 0 <= i && i < grid.size();
	bool colInbound = 0 <= j && j < grid[0].size();
	if (!rowInbound || !colInbound)
		return 0;
	if (grid[i][j] != 1)
		return 0;
	char pi = char(i) + '0';
	char pj = char(j) + '0';
	string pos;
	pos += pi;
	pos += ",";
	pos += pj;
	if (visited.find(pos) != visited.end())
		return 0;
	int count = 1;
	visited.insert(pos);
	count += countArea(grid, i - 1, j, visited);
	count += countArea(grid, i, j - 1, visited);
	count += countArea(grid, i + 1, j, visited);
	count += countArea(grid, i, j + 1, visited);
	return count;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
	int mx = 0;
	unordered_set<string> visited;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == 1)
			{
				mx = max(mx, countArea(grid, i, j, visited));
			}
		}
	}
	return mx;
}

int main()
{
	vector<vector<int>> grid = {
		{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

	cout << maxAreaOfIsland(grid);
}