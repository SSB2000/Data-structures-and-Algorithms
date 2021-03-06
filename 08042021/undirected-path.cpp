// Write a function, undirectedPath, that takes in an array of edges for an undirected graph and two nodes (nodeA, nodeB). The function should return a boolean indicating whether or not there exists a path between nodeA and nodeB.

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;

#define pb push_back
#define mk make_pair

typedef vector<pair<char, char>> vp;
typedef map<char, vector<char>> mv;

void printGraph(mv &graph)
{
	for (auto it : graph)
	{
		const char key = it.first;
		vector<char> values;
		for (auto val : it.second)
		{
			values.pb(val);
		}
		cout << key << ": ";
		for (auto val : values)
		{
			cout << val << ' ';
		}
		cout << '\n';
	}
}

mv makeGraph(vp &edges)
{
	mv graph;

	for (auto pr : edges)
	{
		char key1 = pr.first;
		char key2 = pr.second;
		if (graph.find(key1) == graph.end())
			graph[key1] = {};
		if (graph.find(key2) == graph.end())
			graph[key2] = {};
		graph[key1].pb(key2);
		graph[key2].pb(key1);
	}

	return graph;
}

void printSet(unordered_set<char> &visited)
{
	for (auto it : visited)
	{
		cout << it << ' ';
	}
	cout << '\n';
}

// BFS iterative
bool hasPathbfs(mv &graph, char src, char dst)
{
	if (src == dst)
		return true;
	unordered_set<char> visited;
	queue<char> que;
	que.push(src);
	while (!que.empty())
	{
		const char curr = que.front();
		visited.insert(curr);
		if (curr == dst)
			return true;
		que.pop();
		for (char neibhor : graph[curr])
		{
			if (visited.find(neibhor) == visited.end())
				que.push(neibhor);
		}
	}
	return false;
}

bool undirectedPath(vp &edges, char src, char dst)
{
	mv graph = makeGraph(edges);
	return hasPathbfs(graph, src, dst);
}

int main()
{
	vp edges1;
	edges1.pb(mk('i', 'j'));
	edges1.pb(mk('k', 'i'));
	edges1.pb(mk('m', 'k'));
	edges1.pb(mk('k', 'l'));
	edges1.pb(mk('o', 'n'));
	cout << undirectedPath(edges1, 'j', 'm'); // true;
	cout << endl;

	vp edges2;
	edges2.pb(mk('i', 'j'));
	edges2.pb(mk('k', 'i'));
	edges2.pb(mk('m', 'k'));
	edges2.pb(mk('k', 'l'));
	edges2.pb(mk('o', 'n'));
	cout << undirectedPath(edges2, 'i', 'o'); // false;
	cout << endl;

	vp edges3;
	edges3.pb(mk('b', 'a'));
	edges3.pb(mk('c', 'a'));
	edges3.pb(mk('b', 'c'));
	edges3.pb(mk('q', 'r'));
	edges3.pb(mk('q', 's'));
	edges3.pb(mk('q', 'u'));
	edges3.pb(mk('q', 't'));
	cout << undirectedPath(edges3, 'a', 'c'); // true
}
