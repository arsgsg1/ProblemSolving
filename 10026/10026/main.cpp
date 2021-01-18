#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MAX_SIZE 100
int N;
char color[MAX_SIZE][MAX_SIZE];
int bmap1[MAX_SIZE][MAX_SIZE];
int bmap2[MAX_SIZE][MAX_SIZE];
queue<pair<int, int>> q;
int dirRow[] = { -1, 1, 0, 0 };
int dirCol[] = { 0, 0, -1, 1 };
int cnt1 = 0, cnt2 = 0;
void bfs1(int row, int col, char ch)
{
	cnt1 += 1;
	q.push({ row, col });
	bmap1[row][col] = cnt1;
	int nr, nc, r, c;
	while (!q.empty()){
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (bmap1[nr][nc] == 0 && ch == color[nr][nc]) {
				q.push({ nr, nc });
				bmap1[nr][nc] = cnt1;
			}
		}
	}
}
void bfs2(int row, int col, char ch)
{
	cnt2 += 1;
	q.push({ row, col });
	bmap2[row][col] = cnt2;
	int nr, nc, r, c;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			
			if (bmap2[nr][nc] == 0 && 
				ch == color[nr][nc] && ch == 'B') {
				q.push({ nr, nc });
				bmap2[nr][nc] = cnt2;
			}
			else if (bmap2[nr][nc] == 0 && 
				'B' != color[nr][nc] && ch != 'B') {
				q.push({ nr, nc });
				bmap2[nr][nc] = cnt2;
			}
		}
	}
}
void sim()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (bmap1[i][j] == 0) 
				bfs1(i, j, color[i][j]);
			if (bmap2[i][j] == 0) 
				bfs2(i, j, color[i][j]);
		}
	}
}
int main()
{
	string str;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			color[i][j] = str[j];
	}
	sim();
	printf("%d %d\n", cnt1, cnt2);
	return 0;
}