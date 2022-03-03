#include <iostream>
using namespace std;
#define MAX_LEN 20
#define HORI
#define VERT
#define DIAG
int field[MAX_LEN][MAX_LEN] = { {0, 0} };
int N;
int dirRow[] = { 0, 1, 1 };
int dirCol[] = { 1, 0, 1 };	//수평, 수직, 대각
int dfs(int srow, int scol, int spipe)
{
	int row, col, pipe, result = 0;
	for (int i = 0; i < 3; i++) {
		row = srow + dirRow[i];
		col = scol + dirCol[i];
		pipe = i;
		//벽이거나 범위를 벗어나는 행동
		if (field[row][col] == 1 || row > N || col > N) {
			continue;
		}
		//파이프가 대각선으로 놓일 경우
		if (pipe == 2 && (field[srow + 1][scol] == 1 || field[srow][scol + 1] == 1)) {
			continue;
		}
		//수평, 수직에서 수직, 수평으로 가려할 때
		if ((spipe == 0 && pipe == 1) || (spipe == 1 && pipe == 0)) {
			continue;
		}
		//파이프의 한쪽끝이 (N, N)에 도달할 때
		if (row == N && col == N) {
			return 1;
		}
		result += dfs(row, col, pipe);
	}
	return result;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> field[i][j];
		}
	}
	printf("%d\n", dfs(1, 2, 0));
	return 0;
}