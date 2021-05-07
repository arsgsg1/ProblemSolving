#include <iostream>
using namespace std;
#define MAX_SIZE 101
long long dp[MAX_SIZE][21];
int arr[MAX_SIZE];
int last;
int N;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	dp[1][arr[1]] = 1;
	last = arr[N];
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] == 0)
				continue;
			if (j + arr[i] <= 20) {
				dp[i][j + arr[i]] += dp[i - 1][j];
			}
			if (j - arr[i] >= 0) {
				dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	cout << dp[N - 1][last];
	return 0;
}