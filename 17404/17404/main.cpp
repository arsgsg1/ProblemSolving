#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1000
#define INF 987654321
int dp[MAX_SIZE][3];
int color[MAX_SIZE][3];
int N;
void setting()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			dp[i][j] = INF;
}
int main()
{
	int result = INF;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &color[i][j]);
	setting();
	dp[0][0] = color[0][0];
	dp[0][1] = color[0][1];
	dp[0][2] = color[0][2];
	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (k == j)
				dp[0][j] = color[0][j];
			else
				dp[0][j] = INF;
		}
		for (int i = 1; i < N; i++) {
			dp[i][0] = min(dp[i - 1][1] + color[i][0], dp[i - 1][2] + color[i][0]);
			dp[i][1] = min(dp[i - 1][0] + color[i][1], dp[i - 1][2] + color[i][1]);
			dp[i][2] = min(dp[i - 1][0] + color[i][2], dp[i - 1][1] + color[i][2]);
		}
		for (int j = 0; j < 3; j++) {
			if (k != j)
				result = min(result, dp[N - 1][j]);
		}
	}
	printf("%d\n", result);
	return 0;
}