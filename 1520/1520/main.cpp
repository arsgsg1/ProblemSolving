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
	//기저사례
	if (row == N - 1 && col == M - 1)
		return 1;

	//방문하지 않은 탐색 경로
	if (dp[row][col] == -1) {
		dp[row][col] = 0; //방문처리
		int nr, nc;
		for (int i = 0; i < 4; i++) {
			nr = row + dirRow[i];
			nc = col + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			//다음 칸이 현재 칸보다 작다면, 탐색
			if (m[row][col] > m[nr][nc]) 
				//중복문제를 방지하기 위해 dfs로 탐색
				dp[row][col] += dfs(nr, nc); 
		}
	}
	//다음 칸이 이미 방문한 칸이라면, 더 이상 탐색하지 않고 경우의 수를 +1 한다.
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