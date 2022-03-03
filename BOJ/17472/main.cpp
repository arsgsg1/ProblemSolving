/*
- �ٸ��� ���̴� 2�̻��̾�� ��
- �ٸ��� ������ �߰��� �ٲ� �� ����, ����, ���� �� �߿� �ϳ�
- �ٸ��� �� ���� ���� �����ؾ� ��
output : ��� ���� �����ϴ� �ٸ� ������ �ּڰ�, ������ �Ұ����ϸ� -1

������ ���� �����ϴ� ��� : BFS
���� ª�� ���̸� ���� �ٸ� <= ���� ��� ĭ���� 4�������� �ٸ��� ���ƺ� (����)
���� ª�� ���̸� ���� �ٸ��� ã�� ��� = ����
��� ���� �����ϴ� = ũ�罺Į, ����
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int W, H;
int field[10][10];
int island[10][10];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
int parent[100];
typedef struct bridge {
	int dist;
	int fromRow, fromCol;
	int toRow, toCol;
};
bool cmp(const bridge& b1, const bridge& b2)
{
	return b1.dist < b2.dist;
}
int getParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = getParent(parent[x]);
}
void _union(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}
bool _find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a == b)
		return true;
	else
		return false;
}
void makeBridge(int row, int col, vector<bridge>& bridges)
{
	int nr, nc;
	bridge b;
	b.fromRow = row;
	b.fromCol = col;
	for (int i = 0; i < 4; i++) {
		int dist = 1;
		while (1) {
			nr = row + (dirRow[i] * dist);
			nc = col + (dirCol[i] * dist);
			if (island[nr][nc] == island[row][col])
				break;
			else if (nr < 0 || nc < 0 || nr >= H || nc >= W)
				break;
			else if (1 <= island[nr][nc] && island[nr][nc] != island[row][col]) {
				//�� ĭ���� �����߱� ������ -1
				dist--;
				if (dist < 2)
					break;
				b.dist = dist;
				b.toRow = nr;
				b.toCol = nc;
				bridges.push_back(b);
				break;
			}
			dist++;
		}
	}
}
void bfs(int row, int col, int cnt)
{
	queue<pair<int, int>> q;
	q.push({ row, col });
	island[row][col] = cnt;
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= H || nc >= W)
				continue;
			if (island[nr][nc] == 0 && field[nr][nc] == 1) {
				q.push({ nr, nc });
				island[nr][nc] = cnt;
			}
		}
	}
}
int main()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			cin >> field[i][j];
	for (int i = 0; i < 100; i++)
		parent[i] = i;
	int cnt = 1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (field[i][j] == 1 && island[i][j] == 0) {
				bfs(i, j, cnt++);
			}
		}
	}
	vector<bridge> bridges;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (field[i][j] == 1) {
				makeBridge(i, j, bridges);
			}
		}
	}
	sort(bridges.begin(), bridges.end(), cmp);
	int answer = 0, bridgeCnt = 0;
	for (const auto& b : bridges) {
		int dist = b.dist;
		int from = island[b.fromRow][b.fromCol], to = island[b.toRow][b.toCol];
		if (!_find(from, to)) {
			answer += dist;
			_union(from, to);
			bridgeCnt++;
		}
	}
	if (bridgeCnt != cnt - 2)
		printf("%d\n", -1);
	else
		printf("%d\n", answer);
	return 0;
}