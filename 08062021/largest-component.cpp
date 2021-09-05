// largest component

// Write a function, largestComponent, that takes in the adjacency list of an undirected graph. The function should return the size of the largest connected component in the graph.

#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

#define pb push_back

typedef vector<int> vi;
typedef unordered_map<int, vi> umiv;
typedef unordered_set<int> us;
typedef queue<int> qi;

// BFS iteration
// Traverse through 1 island in one go
void printSet(us &visited)
{
	for (auto it : visited)
	{
		std::cout << it << ' ';
	}
	std::cout << '\n';
}

int count(umiv &graph, int src, us &visited)
{
	qi que;
	if (visited.find(src) != visited.end())
		return 0;
	que.push(src);
	int num = 1;
	while (!que.empty())
	{
		const int curr = que.front();
		visited.insert(curr);
		que.pop();
		for (int neighbor : graph[curr])
		{
			if (visited.find(neighbor) == visited.end())
			{
				que.push(neighbor);
				num++;
			}
		}
	}
	return num;
}

// max node island
int largestComponent(umiv graph)
{
	us visited;
	int mx = 0;
	for (auto it : graph)
	{
		int c = count(graph, it.first, visited);
		// cout << it.first << " " << c << '\n';
		// printSet(visited);
		mx = max(mx, c);
	}
	return mx;
}

int main()
{
	umiv graph1;
	graph1[0] = {8, 1, 5};
	graph1[1] = {0};
	graph1[5] = {0, 8};
	graph1[8] = {0, 5};
	graph1[2] = {3, 4};
	graph1[3] = {2, 4};
	graph1[4] = {3, 2};
	std::cout << largestComponent(graph1) << '\n'; // 4;

	umiv graph2;
	graph2[1] = {2};
	graph2[2] = {1, 8};
	graph2[6] = {7};
	graph2[9] = {8};
	graph2[7] = {6, 8};
	graph2[8] = {9, 7, 2};
	std::cout << largestComponent(graph2) << '\n'; // 6;

	umiv graph0;
	graph0[3] = {};
	graph0[4] = {6};
	graph0[6] = {4, 5, 7, 8};
	graph0[8] = {6};
	graph0[7] = {6};
	graph0[5] = {6};
	graph0[1] = {2};
	graph0[2] = {1};
	std::cout << largestComponent(graph0) << '\n'; // 5;

	umiv graph3;
	std::cout << largestComponent(graph3) << '\n'; // 0;

	umiv graph4;
	graph4[0] = {4, 7};
	graph4[1] = {};
	graph4[2] = {};
	graph4[3] = {6};
	graph4[4] = {0};
	graph4[6] = {3};
	graph4[7] = {0};
	graph4[8] = {};
	std::cout << largestComponent(graph4) << '\n'; // 3;
}