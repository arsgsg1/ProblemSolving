#include <iostream>
#include <string>
#include <deque>
using namespace std;
#define MAX_SIZE 100
string arr[MAX_SIZE];
int MAX_COL, MAX_ROW;
int crash[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
deque<pair<int, int>> dq;
void bfs(int row, int col)
{
	dq.push_back({ row, col });
	visit[row][col] = true;
	int r, c, nr, nc;
	while (!dq.empty()) {
		r = dq.front().first;
		c = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= MAX_ROW || nc >= MAX_COL)
				continue;
			if (arr[nr][nc] == '0' && visit[nr][nc] == false) {
				dq.push_front({ nr, nc });
				visit[nr][nc] = true;
				crash[nr][nc] = crash[r][c];
			}
			else if (arr[nr][nc] == '1' && visit[nr][nc] == false) {
				dq.push_back({ nr, nc });
				visit[nr][nc] = true;
				crash[nr][nc] = crash[r][c] + 1;
			}
		}
	}
}
int main()
{
	cin >> MAX_COL >> MAX_ROW;
	for (int i = 0; i < MAX_ROW; i++)
		cin >> arr[i];
	bfs(0, 0);
	printf("%d\n", crash[MAX_ROW - 1][MAX_COL - 1]);
	return 0;
}