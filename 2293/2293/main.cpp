#include <iostream>
#include <vector>
using namespace std;
int dp[10001] = { 0, };
int N, K;
int main()
{
	cin >> N >> K;
	vector<int> coins(N, 0);
	for (int i = 0; i < N; i++) cin >> coins[i];
	dp[0] = 1;
	for (int n = 0; n < N; n++) {
		for (int k = coins[n]; k <= K; k++) {
			dp[k] = dp[k] + dp[k - coins[n]];
		}
	}
	printf("%d\n", dp[K]);
	return 0;
}