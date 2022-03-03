#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001] = { 0, };
int dp[100001] = { 0, };
int N;
int main()
{
	int result = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	result = dp[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		result = max(dp[i], result);
	}
	printf("%d\n", result);
	return 0;
}