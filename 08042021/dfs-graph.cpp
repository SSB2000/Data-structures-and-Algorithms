#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

void dfsPrintI(map<char, vector<char>>& graph, char src)
{
	stack<char> stc;
	stc.push(src);
	while(!stc.empty())
	{
		const char curr = stc.top();
		stc.pop();
		cout << curr << "->";
		for(char neib : graph[curr])
		{
			stc.push(neib);
		}
	}
}

void dfsPrintR(map<char, vector<char>>& graph, char source)
{
	cout << source << "->";
	for (char neib : graph[source])
	{
		dfsPrintR(graph, neib);
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
	
	dfsPrintI(graph, 'a');
	cout << endl;
	dfsPrintR(graph, 'a');
}