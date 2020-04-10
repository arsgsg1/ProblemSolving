#include <iostream>
#include <string>
#include <queue>
using namespace std;
bool bfs[2][1002][1002] = { {false, false, false} };
int field[1002][1002] = { {0,0} };
int n, m;
int dirRow[] = { 1, -1, 0, 0 };
int dirCol[] = { 0, 0, 1, -1 };
typedef struct {
	int block;
	int row;
	int col;
	int cnt;
}VERTEX;
int Solution(queue<VERTEX>& q)
{
	VERTEX v, next;
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		if (n == v.row && m == v.col) {
			return v.cnt;
		}
		for (int i = 0; i < 4; i++) {
			next.row = v.row + dirRow[i];
			next.col = v.col + dirCol[i];
			//���� �ʰ�
			if (next.row < 1 || next.col < 1 ||
				next.row > n || next.col > m) {
				continue;
			}
			//���� �μ� ���°ų� ���� �μ��� ���� ���¿��� �湮���� ���� ���̶��
			if (field[next.row][next.col] == 0 &&
				bfs[v.block][next.row][next.col] == false) {
				next.block = v.block;
				next.cnt = v.cnt + 1;
				q.push(next);
				bfs[next.block][next.row][next.col] = true;
			}
			//���� ������ ���� �μ��� ���� ���¶��
			else if (field[next.row][next.col] == 1 && v.block == 0) {
				next.block = 1;
				next.cnt = v.cnt + 1;
				q.push(next);
				bfs[next.block][next.row][next.col] = true;
			}
		}
	}
	return -1;
}

int main()
{
	queue<VERTEX> q;
	cin >> n >> m;
	string str;
	for (int i = 1; i <= n; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			field[i][j + 1] = str[j] - '0';
		}
	}
	VERTEX v;
	v.row = 1;
	v.col = 1;
	v.cnt = 1;
	v.block = 0;
	bfs[v.block][v.row][v.col] = true;
	q.push(v);
	printf("%d\n", Solution(q));
	return 0;
}