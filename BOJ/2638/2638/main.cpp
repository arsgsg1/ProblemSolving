#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_SIZE 102
int N, M;
int field[MAX_SIZE][MAX_SIZE] = { {2, 2} };
int dirRow[] = { 0,0,1, -1 };
int dirCol[] = { 1, -1, 0, 0 };
void bfs(int row, int col)
{
	queue<pair<int, int>> q;
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (field[i][j] == 2) {
				q.push({ i, j });
			}
		}
	}
	int nr, nc;
	while (!q.empty()){
		int row = q.front().first;
		int col = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = row + dirRow[i];
			nc = col + dirCol[i];
			if (nr < 0 || nc < 0 ||
				nr > N || nc > M) {
				continue;
			}
			if (field[nr][nc] == 0) {
				q.push({ nr, nc });
				field[nr][nc] = 2;
			}
		}
	}
}
int CountDisappear(int row, int col, vector<pair<int, int>>& v)
{
	int cnt = 0;
	int nr, nc;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (field[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					nr = i + dirRow[k];
					nc = j + dirCol[k];
					if (field[nr][nc] == 2) {
						++cnt;
					}
				}
				if (cnt >= 2) {
					v.push_back({ i, j });
				}
				cnt = 0;
			}
		}
	}

	for (const auto& item : v) 
		field[item.first][item.second] = 2;

	return v.size();
}
int main()
{
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			field[i][j] = 2;
		}
	}
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> field[i][j];
		}
	}
	int time = 0;
	vector<pair<int, int>> v;
	while (1) {
		bfs(0, 0);
		if (CountDisappear(0, 0, v) == 0) {
			break;
		}
		++time;
		v.clear();
	}
	printf("%d\n", time);
	return 0;
}