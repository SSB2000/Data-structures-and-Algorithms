#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

int diskStacking(vector<vector<int>> &disk)
{
	int count = INT_MIN;
	int len = disk.size();
	vector<int> height(len, 0);
	for(int i = 0; i < len; ++i)
	{
		height[i] = disk[i][2];
	}
	for(int i = 0; i < len; ++i)
	{
		vector<int> currd = disk[i];
		for(int j = 0; j < i; ++j)
		{
			vector<int> otherd = disk[j];
			if(otherd[0] < currd[0] && otherd[1] < currd[1] && otherd[2] < currd[2])
			{
				height[i] = max(height[i], currd[2] + height[j]);
			}
		}
	}
	return *max_element(height.begin(), height.end());
	
}

bool comp(vector<int>& a, vector<int>& b)
{
	return a[a.size() - 1] < b[b.size() - 1];
}	

void sortByLastValue(vector<vector<int>>& arr)
{
	sort(arr.begin(), arr.end(), comp);
}	


int main()
{
	srand(time(0));
	vector<vector<int>> disk {
		{2, 2, 1},
		{2, 1, 2},
		{3, 2, 3},
		{2, 3, 4},
		{4, 4, 5},
		{2, 2, 8}	
	}; 
	/*
	for(int i = 0; i < 6; ++i)
	{
		for(int ele : disk[i])
			cout << ele << ' ';
		cout << '\n';
	}
	cout << endl;	
	*/
	sortByLastValue(disk);
	/*
	for(int i = 0; i < 6; ++i)
	{
		for(int ele : disk[i])
			cout << ele << ' ';
		cout << '\n';
	}
	*/
	cout << diskStacking(disk) << endl;
}
