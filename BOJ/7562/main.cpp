#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX_SIZE 300
int N;
int start_row, start_col;
int goal_row, goal_col;
int dirRow[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dirCol[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
void bfs(int visit[][MAX_SIZE])
{
	queue<pair<int, int>> q;
	q.push({ start_row, start_col });
	visit[start_row][start_col] = 1;
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		if (r == goal_row && c == goal_col) {
			break;
		}
		for (int i = 0; i < 8; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
				continue;
			}
			if (visit[nr][nc] == 0) {
				visit[nr][nc] = visit[r][c] + 1;
				q.push({ nr, nc });
			}
			else if (visit[nr][nc] > visit[r][c] + 1) {
				visit[nr][nc] = visit[r][c] + 1;
				q.push({ nr, nc });
			}
		}
	}
}
int main()
{
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int visit[MAX_SIZE][MAX_SIZE];
		memset(visit, 0, sizeof(visit));
		scanf("%d", &N);
		scanf("%d %d", &start_row, &start_col);
		scanf("%d %d", &goal_row, &goal_col);
		bfs(visit);
		printf("%d\n", --visit[goal_row][goal_col]);
	}

	return 0;
}