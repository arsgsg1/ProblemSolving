#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_LEN 1001
int arr[MAX_LEN] = { 0, };
int dp[MAX_LEN] = { 0, };

int Solution(int n, int* arr)
{
	int SubMax = 0, Max = 0;
	for (int i = 1; i <= n; i++) {
		SubMax = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				SubMax = max(dp[j], SubMax);
			}
		}
		dp[i] = SubMax + 1;
		Max = max(Max, dp[i]);
	}
	return Max;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	printf("%d\n", Solution(n, arr));
	return 0;
}