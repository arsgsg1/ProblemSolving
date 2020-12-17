#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
int dp[10001];
int main()
{	
	fill(&dp[0], &dp[10001], 987654321);
	cin >> N >> K;
	vector<int> coins(N, 0);
	dp[0] = 0;
	for (int i = 0; i < N; i++)cin >> coins[i];
	for (int n = 0; n < N; n++) {
		for (int k = coins[n]; k <= K; k++) {
			dp[k] = min(dp[k], dp[k - coins[n]] + 1);
		}
	}
	if (dp[K] == 987654321)
		printf("-1\n");
	else
		printf("%d\n", dp[K]);
	return 0;
}