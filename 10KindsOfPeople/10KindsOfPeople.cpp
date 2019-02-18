// 10 Kinds Of People
// https://open.kattis.com/problems/10kindsofpeople
// Time Limit Exceeded

#include "pch.h"
#include <iostream>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

bool BFS(char**, int, int, int, int, int, int);
bool Astar(char**, int, int, int, int, int, int);
int mannhattan(int, int, int, int);
void print_map(char**, int, int, int, int);

int main()
{
	int r;
	cin >> r;

	int c;
	cin >> c;

	char** map = new char*[r];
	for (int i = 0; i < r; i++)
	{
		map[i] = new char[c];
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1;
		cin >> y1;
		cin >> x2;
		cin >> y2;
		x1--;
		y1--;
		x2--;
		y2--;

		if (map[x1][y1] != map[x2][y2])
		{
			cout << "neither" << endl;
		}
		else
		{
			if (BFS(map, r, c, x1, y1, x2, y2))
			{
				switch (map[x1][y1])
				{
				case '0':
					cout << "binary" << endl;
					break;
				case '1':
					cout << "decimal" << endl;
					break;
				}
			}
			else
			{
				cout << "neither" << endl;
			}
		}

	}
}

bool BFS(char** layout, int rows, int cols, int r1, int c1, int r2, int c2)
{
	char path = layout[r1][c1];
	int* duple = new int[2]{ r1, c1 };

	queue<int*> q;
	q.push(duple);

	map<int, bool> visited;

	while (!q.empty())
	{
		int* point = q.front();
		q.pop();
		int r = point[0];
		int c = point[1];
		if (r == r2 && c == c2)
		{
			return true;
		}
		visited[r * cols + c] = true;
		//print_map(layout, rows, cols, r, c);
		if (r - 1 >= 0 && !visited[(r - 1) * cols + c] && layout[r - 1][c] == path)
		{
			int* newp = new int[2]{ r - 1, c };
			q.push(newp);
		}
		if (r + 1 < rows && !visited[(r + 1) * cols + c] && layout[r + 1][c] == path)
		{
			int* newp = new int[2]{ r + 1, c };
			q.push(newp);
		}
		if (c - 1 >= 0 && !visited[r * cols + (c - 1)] && layout[r][c - 1] == path)
		{
			int* newp = new int[2]{ r, c - 1 };
			q.push(newp);
		}
		if (c + 1 < cols && !visited[r * cols + (c + 1)] && layout[r][c + 1] == path)
		{
			int* newp = new int[2]{ r, c + 1 };
			q.push(newp);
		}

		delete[] point;
	}

	return false;
}

bool Astar(char** layout, int rows, int cols, int r1, int c1, int r2, int c2)
{
	char path = layout[r1][c1];
	int* duple = new int[2]{ r1, c1 };

	queue<int*> q;
	q.push(duple);

	map<int, bool> visited;

	while (!q.empty())
	{
		int* point = q.front();
		q.pop();
		int r = point[0];
		int c = point[1];
		if (r == r2 && c == c2)
		{
			return true;
		}
		visited[r * cols + c] = true;
		//print_map(layout, rows, cols, r, c);
		if (r - 1 >= 0 && !visited[(r - 1) * cols + c] && layout[r - 1][c] == path)
		{
			int* newp = new int[2]{ r - 1, c };
			q.push(newp);
		}
		if (r + 1 < rows && !visited[(r + 1) * cols + c] && layout[r + 1][c] == path)
		{
			int* newp = new int[2]{ r + 1, c };
			q.push(newp);
		}
		if (c - 1 >= 0 && !visited[r * cols + (c - 1)] && layout[r][c - 1] == path)
		{
			int* newp = new int[2]{ r, c - 1 };
			q.push(newp);
		}
		if (c + 1 < cols && !visited[r * cols + (c + 1)] && layout[r][c + 1] == path)
		{
			int* newp = new int[2]{ r, c + 1 };
			q.push(newp);
		}

		delete[] point;
	}

	return false;
}

int mannhattan(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

void print_map(char ** map, int rows, int cols, int r, int c)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == r && j == c)
			{
				cout << "X";
			}
			else
			{
				cout << map[i][j];
			}
		}
		cout << endl;
	}
	cout << endl;
}
