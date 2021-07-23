#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX_SIZE 300
int R, C;
int arr[MAX_SIZE][MAX_SIZE];
int island[MAX_SIZE][MAX_SIZE];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
void melt()
{
	int temp[MAX_SIZE][MAX_SIZE];
	memcpy(temp, arr, sizeof(arr));
	int melt_height = 0;
	for (int i = 1; i < R; i++) {
		for (int j = 1; j < C; j++) {
			if (arr[i][j] >= 1) {
				melt_height = !arr[i - 1][j] + !arr[i][j - 1] + !arr[i + 1][j] + !arr[i][j + 1];
				temp[i][j] = arr[i][j] - melt_height < 0 ? 0 : arr[i][j] - melt_height;
			}
		}
	}
	memcpy(arr, temp, sizeof(arr));
}
void island_bfs(int row, int col, int cnt)
{
	queue<pair<int, int>> q;
	q.push({ row, col });
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C)
				continue;
			if (island[nr][nc] == 0 && arr[nr][nc] >= 1) {
				q.push({ nr, nc });
				island[nr][nc] = cnt;
			}
		}
	}
}
int island_count()
{
	int cnt = 1;
	memset(island, 0, sizeof(island));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (island[i][j] == 0 && arr[i][j] >= 1) {
				island_bfs(i, j, cnt++);
			}
		}
	}
	return cnt - 1;
}
int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int time = 0, island_cnt = 0;
	while (1) {
		island_cnt = island_count();
		if (island_cnt >= 2)
			break;
		else if (island_cnt == 0) {
			time = 0;
			break;
		}
		melt();
		time++;
	}
	printf("%d\n", time);
	return 0;
}