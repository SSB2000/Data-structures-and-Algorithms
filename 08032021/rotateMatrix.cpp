// CTCI 1.7: Rotate Matrix: Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees.Can you do this in place ?

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

void transpose(vector<vector<int>> &matrix)
{
	int row = matrix.size();
	int col = matrix[0].size();
	vector<vector<int>> res(col, vector<int>(row, 0));
	int i, j, temp;
	for (i = 0; i < row; i++)
	{
		for (j = i; j < col; j++)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void rotate(vector<vector<int>> &matrix)
{
	transpose(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		reverse(matrix[i].begin(), matrix[i].end());
	}
}

void rotateCTCI(vector<vector<int>> &matrix)
{
}

int main()
{
	int row = 4, col = 4;
	vector<vector<int>> matrix(row, vector<int>(col));
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			matrix[i][j] = rand() % (row * col);
		}
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	rotate(matrix);
	rotateCTCI(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}