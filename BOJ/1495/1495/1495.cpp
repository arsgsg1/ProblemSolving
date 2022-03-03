#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1001
int N, S, M;
int arr[101];
int dp[101][MAX_SIZE];
int main()
{
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[0][S] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (dp[i - 1][j] == 0)
				continue;
			if (j - arr[i] >= 0)
				dp[i][j - arr[i]] = 1;
			if (j + arr[i] <= M)
				dp[i][j + arr[i]] = 1;
		}
	}
	for (int i = M; i >= 0; i--) {
		if (dp[N][i] == 1) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}