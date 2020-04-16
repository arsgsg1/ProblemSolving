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
		//수평, 수직에서 수직, 수평으로 가려할 때
		if ((spipe == 0 && pipe == 2) || (spipe == 2 && pipe == 0)) {
			continue;
		}
		if (srow == N && scol == N) {
			return 1;
		}
		result += dfs(row, col, pipe);
	}
	return result;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
		}
	}
	return 0;
}