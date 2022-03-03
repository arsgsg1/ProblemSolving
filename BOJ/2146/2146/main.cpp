#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_SIZE 100
int N;
int m[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE];
vector<queue<pair<pair<int, int>, int>>> v;
int dirRow[] = { -1, 1, 0, 0 };
int dirCol[] = { 0, 0, -1, 1 };
int result = 987654321;
void sim()
{
	int r, c, nr, nc, nd, cnt = 0;
	int visit_cp[MAX_SIZE][MAX_SIZE];
	for (auto& item : v) {
		memcpy(visit_cp, visit, sizeof(visit));
		cnt++;
		while (!item.empty()) {
			r = item.front().first.first;
			c = item.front().first.second;
			visit_cp[r][c] = cnt;
			nd = item.front().second + 1;
			item.pop();
			for (int i = 0; i < 4; i++) {
				nr = r + dirRow[i];
				nc = c + dirCol[i];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)
					continue;
				if (!visit_cp[nr][nc] && !m[nr][nc]) {
					visit_cp[nr][nc] = cnt;
					item.push({ {nr, nc}, nd });
				}
				else if (visit_cp[nr][nc]
					&& visit_cp[nr][nc] != visit_cp[r][c]) {
					result = min(nd, result);
				}
			}
		}
	}
}
void bfs(int row, int col, int cnt)
{
	queue<pair<int, int>> q;
	queue<pair<pair<int, int>, int>> vq;
	q.push({ row, col });
	visit[row][col] = cnt;
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (!visit[nr][nc] && m[nr][nc]) {
				visit[nr][nc] = cnt;
				q.push({ nr, nc });
			}
			if (!visit[nr][nc] && !m[nr][nc]) {
				vq.push({ {nr, nc}, 0 });
			}
		}
	}
	v.push_back(vq);
}
void Search()
{
	int cnt = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (!visit[r][c] && m[r][c])
				bfs(r, c, ++cnt);
		}
	}
	sim();
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &m[i][j]);
	Search();
	printf("%d\n", result);
	return 0;
}