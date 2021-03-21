#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX_SIZE 1001
int N, M;
int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int dfs(int r, int c)
{
	if (r == N || c == M)
		return 0;
	if (r == N - 1 && c == M - 1)
		return arr[r][c];
	if (dp[r][c] == -1) {
		dp[r][c] = arr[r][c];
		dp[r][c] += max(dfs(r + 1, c), max(dfs(r, c + 1), dfs(r + 1, c + 1)));
	}
	return dp[r][c];
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(0, 0));
	return 0;
}