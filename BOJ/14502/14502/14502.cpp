#include <iostream>
#include <queue>
using namespace std;
#define MAX_LEN 8
int N, M;
int field[MAX_LEN][MAX_LEN] = { {0,0} };
int dirRow[] = { 1, -1, 0, 0 };
int dirCol[] = { 0, 0, -1, 1 };
queue<pair<int, int> > q;

int bfs(queue<pair<int, int> > vq, int bfsField[][MAX_LEN])
{
	int nextRow, nextCol, cnt = 0;
	while (!vq.empty())
	{
		int Row = vq.front().first;
		int Col = vq.front().second;
		vq.pop();
		for (int i = 0; i < 4; i++) {
			nextRow = Row + dirRow[i];
			nextCol = Col + dirCol[i];
			if (nextRow >= 0 && nextRow < N &&
				nextCol >= 0 && nextCol < M) {
				continue;
			}
			if (bfsField[nextRow][nextCol] == 0) {
				bfsField[nextRow][nextCol] = 2;
				vq.push(make_pair(nextRow, nextCol));
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (bfsField[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

int dfs(int wall)
{
	int bfsField[MAX_LEN][MAX_LEN];
	if (wall == 3) {
		memcpy(bfsField, field, sizeof(bfsField));
		return bfs(q, bfsField);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 0) {
				field[i][j] = 1;
				dfs(wall + 1);
				field[i][j] = 0;
			}
		}
	}
	return 0;
}
int main()
{
	int maxCount = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> field[i][j];
			if (field[i][j] == 2)
				q.push(make_pair(N, M));
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 0) {
				field[i][j] = 1;
				maxCount = max(dfs(1), maxCount);
				field[i][j] = 0;
			}
		}
	}
	printf("%d\n", maxCount);
	return 0;
}