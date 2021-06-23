/*
���� �ּҷ� �μ��� �� = �� ĭ�� �켱�Ͽ� Ž��
���� �� ĭ �߿� �켱�Ͽ� Ž���ϴ� ��� => �ڷᱸ�� �켱���� ť Ȥ�� ������ ���� ����
*/
#include <iostream>
#include <deque>
#include <string>
using namespace std;
int Width, Height;
int field[101][101];
int dist[101][101];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
void bfs(int row, int col)
{
	deque<pair<int, int>> dq;
	dist[row][col] = 1;
	dq.push_back({ row, col });
	int r, c, nr, nc;
	while (!dq.empty()) {
		r = dq.front().first;
		c = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr <= 0 || nc <= 0 || nr > Height || nc > Width)
				continue;
			if (dist[nr][nc] == 0) {
				if (field[nr][nc] == 0) {
					dist[nr][nc] = dist[r][c];
					dq.push_front({ nr, nc });
				}
				else {
					dist[nr][nc] = dist[r][c] + 1;
					dq.push_back({ nr, nc });
				}
			}
		}
	}
}
int main()
{
	cin >> Width >> Height;
	string buf;
	for (int i = 1; i <= Height; i++) {
		cin >> buf;
		for (int j = 0; j < buf.length(); j++) {
			if (buf[j] == '1')
				field[i][j + 1] = 1;
			else
				field[i][j + 1] = 0;
		}
	}
	bfs(1, 1);
	printf("%d\n", dist[Height][Width] - 1);
	return 0;
}