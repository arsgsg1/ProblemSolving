#include <iostream>
using namespace std;
int N, M;
#define MAX_SIZE 500
int m[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
int dfs(int row, int col)
{
	//�������
	if (row == N - 1 && col == M - 1)
		return 1;

	//�湮���� ���� Ž�� ���
	if (dp[row][col] == -1) {
		dp[row][col] = 0; //�湮ó��
		int nr, nc;
		for (int i = 0; i < 4; i++) {
			nr = row + dirRow[i];
			nc = col + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			//���� ĭ�� ���� ĭ���� �۴ٸ�, Ž��
			if (m[row][col] > m[nr][nc]) 
				//�ߺ������� �����ϱ� ���� dfs�� Ž��
				dp[row][col] += dfs(nr, nc); 
		}
	}
	//���� ĭ�� �̹� �湮�� ĭ�̶��, �� �̻� Ž������ �ʰ� ����� ���� +1 �Ѵ�.
	return dp[row][col];
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
			dp[i][j] = -1;
		}
	printf("%d\n", dfs(0, 0));
	return 0;
}