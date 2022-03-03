#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 101
#define INF 987654321
int Row, Col, T;
int arr[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE][2];
int dirRow[] = { 1,0,-1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
void bfs()
{
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {1, 1} });
	dist[1][1][0] = 0;
	int r, c, nr, nc, m;
	while (!q.empty()) {
		r = q.front().second.first;
		c = q.front().second.second;
		m = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr <= 0 || nr <= 0 || nr > Row || nc > Col)
				continue;
			//�� ���ο� ������� ��ĭ Ž��
			if (arr[nr][nc] != 1 && dist[nr][nc][m] == INF) {
				//���� ����ٸ� �ð� �����ϰ� ť�� ����
				if (arr[nr][nc] == 2) {
					dist[nr][nc][1] = dist[r][c][0] + 1;
					q.push({ 1, {nr, nc} });
				}
				dist[nr][nc][m] = dist[r][c][m] + 1;
				q.push({ m, {nr, nc} });
			}
			//���� ����ٸ�, ���� ������� �ʰ� Ž��
			else if (m == 1 && dist[nr][nc][m] == INF) {
				dist[nr][nc][m] = dist[r][c][m] + 1;
				q.push({ m, {nr, nc} });
			}
		}
	}
}
int main()
{
	cin >> Row >> Col >> T;
	for (int i = 1; i <= Row; i++) {
		for (int j = 1; j <= Col; j++) {
			scanf("%d", &arr[i][j]);
			dist[i][j][0] = INF;
			dist[i][j][1] = INF;
		}
	}
	bfs();
	int answer = min(dist[Row][Col][0], dist[Row][Col][1]);
	if (answer > T)
		printf("Fail\n");
	else
		printf("%d\n", answer);
	return 0;
}