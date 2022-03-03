#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 50
bool visit[MAX_SIZE][MAX_SIZE] = { {false, false} };
int N, M, result = 987654321;
int m[MAX_SIZE][MAX_SIZE];
int dirRow[] = { -1, 1, 0, 0 };
int dirCol[] = { 0, 0, -1, 1 };
vector<pair<pair<int, int>, int>> virus;
int sim(vector<pair<pair<int, int>, int>> vv)
{
	queue<pair<pair<int, int>, int>> q;
	for (const auto& item : vv)
		q.push(item);
	int bfs[MAX_SIZE][MAX_SIZE] = { {0,} };
	bool visit_cp[MAX_SIZE][MAX_SIZE];
	memcpy(visit_cp, visit, sizeof(visit));
	int nr, nc, r, c, v, time = 0;
	while (!q.empty()) {
		r = q.front().first.first;
		c = q.front().first.second;
		v = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (m[nr][nc] != 1 && !visit_cp[nr][nc]) {
				if (m[nr][nc] == 2) {
					q.push({ {nr, nc}, v + 1 });
					bfs[nr][nc] = bfs[r][c];
				}
				else if(m[nr][nc] == 0) {
					q.push({ {nr, nc}, 0 });
					bfs[nr][nc] = bfs[r][c] + v + 1;
				}
				visit_cp[nr][nc] = true;
				time = max(time, bfs[nr][nc]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if ((m[i][j] == 2 || m[i][j] == 0) && !visit_cp[i][j]) {
				return 987654321;
			}
	}
	return time;
}
void dfs(int row, int col,
	int toPick)
{
	if (toPick == 0) {
		result = min(result, sim(virus));
		return;
	}
	int i = row, j = col;
	for (; i < N; i++) {
		for (; j < N; j++) {
			if (m[i][j] == 2 && !visit[i][j]) {
				virus.push_back({ {i, j}, 0 });
				visit[i][j] = true;
				dfs(i, j, toPick - 1);
				visit[i][j] = false;
				virus.pop_back();
			}
		}
		j = 0;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for(int i = 0; i< N; i++)
		for (int j = 0; j < N; j++) 
			scanf("%d", &m[i][j]);
	dfs(0, 0, M);
	if (result == 987654321)
		printf("-1\n");
	else
		printf("%d\n", result);
	return 0;
}