#include <iostream>
#include <algorithm>
using namespace std;
int N, S, M;
int arr[101];
int dp[101][1001];
int main()
{
	cin >> N >> S >> M;
	dp[0][S] = 1;
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (!dp[i - 1][j])
				continue;
			if (j - arr[i] >= 0)
				dp[i][j - arr[i]] = true;
			if (j + arr[i] <= M)
				dp[i][j + arr[i]] = true;
		}
	}
	for (int i = M; i >= 0; i--) {
		if (dp[N][i]) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}