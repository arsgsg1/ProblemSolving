#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 10001
int N;
int dp[MAX_SIZE] = { 0, }, v[MAX_SIZE] = { 0, };
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &v[i]);
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	for (int i = 3; i <= N; i++) {
		/*
		dp[i] = max(dp[i - 2] + v[i - 1], dp[i - 2] + v[i]);
		dp[i] = max(dp[i - 3] + v[i - 1] + v[i], dp[i]);
		*/
		dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	printf("%d\n", dp[N]);
	return 0;
}