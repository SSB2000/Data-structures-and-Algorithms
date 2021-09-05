// connected components count

// 	Write a function, connectedComponentsCount, that takes in the adjacency list of an undirected graph.The function should return the number of connected components within the graph.

#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <queue>

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
		cout << it << ' ';
	}
	cout << '\n';
}

bool explore(umiv &graph, int src, us &visited)
{
	qi que;
	if (visited.find(src) != visited.end())
		return false;
	que.push(src);
	while (!que.empty())
	{
		const int curr = que.front();
		visited.insert(curr);
		que.pop();
		for (int neighbor : graph[curr])
		{
			if (visited.find(neighbor) == visited.end())
				que.push(neighbor);
		}
	}
	return true;
}

// count islands
int connectedComponenetsCount(umiv graph)
{
	us visited;
	int count = 0;
	for (auto it : graph)
	{
		if (explore(graph, it.first, visited))
			count++;
	}
	return count;
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
	cout << connectedComponenetsCount(graph1) << '\n'; // 2;

	umiv graph2;
	graph2[1] = {2};
	graph2[2] = {1, 8};
	graph2[6] = {7};
	graph2[9] = {8};
	graph2[7] = {6, 8};
	graph2[8] = {9, 7, 2};
	cout << connectedComponenetsCount(graph2) << '\n'; // 1;

	umiv graph4;
	graph4[0] = {4, 7};
	graph4[1] = {};
	graph4[2] = {};
	graph4[3] = {6};
	graph4[4] = {0};
	graph4[6] = {3};
	graph4[7] = {0};
	graph4[8] = {};
	cout << connectedComponenetsCount(graph4) << '\n'; // 5;
}