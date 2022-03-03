#include <iostream>
using namespace std;
#define CONST 10007
int N;
int dp[1001][1001];
/*
dp[N][M] = 길이 M이고 마지막 수가 N인 오르막 수의 개수
dp[N][M] = dp[N - i][M - 1]
*/
int main()
{
	cin >> N;
	for (int i = 0; i < 10; i++)
		dp[i][1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int k = 9; k >= 0; k--) {
			for (int j = 0; j <= k; j++) {
				dp[k][i] += dp[j][i - 1] % CONST;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= 9; i++)
		answer += dp[i][N] % CONST;
	printf("%d\n", answer % CONST);
	return 0;
}