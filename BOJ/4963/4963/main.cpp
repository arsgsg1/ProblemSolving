#include <iostream>
#include <queue>
using namespace std;
int W = 51, H = 51, cnt = 0;
int m[50][50];
bool visit[50][50];
int dirRow[] = { 1, 0, -1, 0, 1, -1, -1, 1};
int dirCol[] = { 0, 1, 0, -1, -1, -1, 1, 1};
void bfs(int row, int col)
{
	int nr, nc;
	queue<pair<int, int>> q;
	q.push({ row, col });
	visit[row][col] = true;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= H || nc >= W)
				continue;
			if (m[nr][nc] && !visit[nr][nc]) {
				q.push({ nr, nc });
				visit[nr][nc] = true;
			}
		}
	}
}
void count()
{
	cnt = 0;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++) {
			if (m[i][j] && !visit[i][j]) {
				bfs(i, j);
				++cnt;
			}
		}
}
int main()
{
	while (1) {
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0)
			break;
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++) {
				scanf("%d", &m[i][j]);
				visit[i][j] = !m[i][j];
			}
		count();
		printf("%d\n", cnt);
	}
	return 0;
}