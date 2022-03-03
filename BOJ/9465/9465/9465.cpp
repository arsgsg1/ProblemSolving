#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_LEN 100003
int dp[2][MAX_LEN] = { {0,0} };

void Print(int n)
{
	for (int i = 0; i <= n; i++) {
		printf("%d ", dp[0][i]);
	}
	printf("\n");
	for (int i = 0; i <= n; i++) {
		printf("%d ", dp[1][i]);
	}
	printf("\n");
	printf("==========\n");
}

int Solution(int n)
{
	for (int i = 1; i <= n; i++) {
		dp[1][i + 1] = max(dp[0][i - 1], dp[0][i]) + dp[1][i + 1];
		dp[0][i + 1] = max(dp[1][i - 1], dp[1][i]) + dp[0][i + 1];
		//Print(n);
	}
	return max(dp[0][n], dp[1][n]);
}
int main()
{
	int TestCase, n;
	cin >> TestCase;
	for (int k = 0; k < TestCase; k++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> dp[0][i];
		}
		for (int j = 1; j <= n; j++) {
			cin >> dp[1][j];
		}
		printf("%d\n", Solution(n));
	}
	
	return 0;
}