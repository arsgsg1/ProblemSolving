#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 501
int N, M;
bool visit[MAX_SIZE][MAX_SIZE];
int field[MAX_SIZE][MAX_SIZE];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
int bfs(int row, int col)
{
	queue<pair<int, int>> q;
	q.push({ row, col });
	visit[row][col] = true;
	int r, c, nr, nc, result = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (visit[nr][nc] == false && field[nr][nc] == 1) {
				visit[nr][nc] = true;
				q.push({ nr, nc });
				result++;
			}
		}
	}
	return result;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &field[i][j]);
	int area = 0, count = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (visit[r][c] == false && field[r][c] == 1) {
				count++;
				area = max(area, bfs(r, c));
			}
		}
	}
	printf("%d\n%d\n", count, area);
	return 0;
}