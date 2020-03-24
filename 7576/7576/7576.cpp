#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_LEN 1000
int dir_x[] = { -1, 0, 1, 0 };
int dir_y[] = { 0, 1, 0, -1 };
int Solution(queue<pair<pair<int, int>, int>>& q, int field[][MAX_LEN], int width, int height)
{
	pair<int, int> p;
	int cur_x, cur_y, cnt = 0, day = 0;
	int next_x, next_y;
	while (!q.empty())
	{
		cur_x = q.front().first.first;
		cur_y = q.front().first.second;
		day = q.front().second;
		if (field[cur_x][cur_y] == 0)
			field[cur_x][cur_y] = day;
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dir_x[i];
			next_y = cur_y + dir_y[i];
			if (next_x < width && next_y < height) {
				if (field[next_x][next_y] == 0) {
					q.push(make_pair(make_pair(next_x, next_y), day + 1));
				}
			}
		}
	}
	return day;
}

int main()
{
	int field[MAX_LEN][MAX_LEN];
	int width, height;
	queue<pair<pair<int, int>, int>> q;
	cin >> width >> height;
	for (int i = 0; i < height; i++) {
		for (int j = 0; i < width; j++) {
			cin >> field[i][j];
			if (field[i][j] == 1) {
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
	}
	Solution(q, field, width, height);
	return 0;
}