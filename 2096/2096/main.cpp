#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int dp[3][2] = { {0,0} };
int main()
{
	vector<int> n(3, 0);
	cin >> N;
	cin >> n[0] >> n[1] >> n[2];
	if (N == 1) {
		printf("%d %d\n", *max_element(n.begin(), n.end()),
			*min_element(n.begin(), n.end()));
		return 0;
	}
	dp[0][0] = n[0];
	dp[0][1] = n[0];

	dp[1][0] = n[1];
	dp[1][1] = n[1];

	dp[2][0] = n[2];
	dp[2][1] = n[2];
	int d0, d1, d2;
	for (int i = 1; i < N; i++) {
		cin >> n[0] >> n[1] >> n[2];
		d0 = dp[0][0];
		d1 = dp[1][0];
		d2 = dp[2][0];
		dp[0][0] = max(n[0] + d0, n[0] + d1);
		dp[1][0] = max(n[1] + d0, max(n[1] + d1, n[1] + d2));
		dp[2][0] = max(n[2] + d1, n[2] + d2);

		d0 = dp[0][1];
		d1 = dp[1][1];
		d2 = dp[2][1];
		dp[0][1] = min(n[0] + d0, n[0] + d1);
		dp[1][1] = min(n[1] + d0, min(n[1] + d1, n[1] + d2));
		dp[2][1] = min(n[2] + d1, n[2] + d2);
	}
	printf("%d %d\n", max(dp[0][0], max(dp[1][0], dp[2][0])), min(dp[0][1], min(dp[1][1], dp[2][1])));
	return 0;
}