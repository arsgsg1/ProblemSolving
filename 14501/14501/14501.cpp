#include <iostream>
#include <algorithm>
#define MAX_LEN 1001
using namespace std;

int Solution(int n, int dp[], int ta[], int pa[])
{
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j + ta[j] <= n) {
				dp[j + ta[j]] = max(dp[j] + pa[j], dp[j + ta[j]]);
			}
			dp[j + 1] = max(dp[j], dp[j + 1]);
		}
	}
	printf("%d", *max_element(dp, dp + n + 1));
	return 0;
}
int main()
{
	int ta[MAX_LEN] = { 0, }, pa[MAX_LEN] = { 0, }, dp[MAX_LEN] = { 0, };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ta[i];
		cin >> pa[i];
	}
	Solution(n, dp, ta, pa);
	return 0;
}
