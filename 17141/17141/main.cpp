#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_SIZE 50
#define INFITITE 10000000
int field[MAX_SIZE][MAX_SIZE] = { {0, 0} };
int virus[MAX_SIZE][MAX_SIZE] = { {0, 0} };
int cp[MAX_SIZE][MAX_SIZE] = { {0, 0} };
int dirRow[] = { 0, 0, 1, -1 };
int dirCol[] = { 1, -1, 0, 0 };
int N, M, result = INFITITE;
void simulation(const vector<pair<int, int>>& pos)
{
	queue<pair<int, int>> q;
	for (const auto& item : pos)
		q.push(item);
	int row, col, nr, nc;
	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			nr = row + dirRow[i];
			nc = col + dirCol[i];
			if (nr < 0 || nr >= N ||
				nc < 0 || nc >= N) {
				continue;
			}
			if (cp[nr][nc] == 0) {
				q.push({ nr, nc });
				cp[nr][nc] = cp[row][col] + 1;
			}
		}
	}
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cp[i][j] == 0) {
				return;
			}
			else {
				time = max(cp[i][j], time);
			}
		}
	}
	result = min(time - 1, result);
}
void dfs(int row, int col, int toPick, vector<pair<int, int>>& pos)
{
	//기저사례 : 놓을 수 있는 바이러스가 더 이상 없을 때
	if (toPick == 0) {
		memcpy(cp, virus, sizeof(cp));
		simulation(pos);
		return;
	}
	int i = row;
	int j = col;

	for (; i < N; i++) {
		for (; j < N; j++) {
			if (field[i][j] == 2 && virus[i][j] == 0) {
				pos.push_back({ i, j });
				virus[i][j] = 1;
				dfs(i, j, toPick - 1, pos);
				pos.pop_back();
				virus[i][j] = 0;
			}
		}
		j = 0;
	}
}
int main()
{
	vector<pair<int, int>> pos;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> field[i][j];
			if(field[i][j] == 1){
				virus[i][j] = -(INFITITE);
			}
		}
	}
	dfs(0, 0, M, pos);
	if (result == INFITITE) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result);
	}
	return 0;
}