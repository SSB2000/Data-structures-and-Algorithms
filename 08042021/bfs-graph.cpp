// Breadth First Search

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

void bfsPrint(map<char, vector<char>>& graph, char src)
{
	queue<char> que;
	que.push(src);
	while(!que.empty())
	{
		const char curr = que.front();
		que.pop();
		cout << curr << "->";
		for(char neib : graph[curr])
		{
			que.push(neib);
		}
	}
}


int main()
{
	map<char, vector<char>> graph;
	graph['a'] = {'b', 'c'};
	graph['b'] = {'d'};
	graph['c'] = {'e'};
	graph['d'] = {'f'};
	graph['e'] = {};
	graph['f'] = {};
	
	bfsPrint(graph, 'a');
	cout << endl;
}