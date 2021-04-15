#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int N;
int answer = 0;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i]++;
		answer = max(answer, dp[i]);
	}
	printf("%d\n", answer);
	return 0;
}