#include <iostream> 
#include <queue> 
#include <algorithm> 
using namespace std;
int dir_x[] = { -1, 0, 1, 0 };
int dir_y[] = { 0, 1, 0, -1 };

bool IsImpossible(vector<vector<int>>& field, int width, int height)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (field[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}

int Solution(queue<pair<pair<int, int>, int>>& q, vector<vector<int>>& field, int width, int height)
{
	pair<int, int> p;
	int cur_x, cur_y, cnt = 0, day = 0;
	int next_x, next_y;
	while (!q.empty())
	{
		cur_x = q.front().first.first;
		cur_y = q.front().first.second;
		day = q.front().second;
		q.pop();
		if (field[cur_x][cur_y] == 0)
			field[cur_x][cur_y] = day;
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dir_x[i];
			next_y = cur_y + dir_y[i];
			if (next_x < height && next_y < width && next_x >= 0 && next_y >= 0) {
				if (field[next_x][next_y] == 0) {
					q.push(make_pair(make_pair(next_x, next_y), day + 1));
				}
			}
		}
	}
	if (IsImpossible(field, width, height))
		return -1;
	else
		return day;
}

int main()
{
	vector<vector<int>> field;
	vector<int> s;
	int width, height, temp;
	queue<pair<pair<int, int>, int>> q;
	cin >> width >> height;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> temp;
			s.push_back(temp);
			if (temp == 1) {
				q.push(make_pair(make_pair(i, j), 0));
			}
		}
		field.push_back(s);
		s.clear();
	}
	printf("%d\n", Solution(q, field, width, height));
	return 0;
}