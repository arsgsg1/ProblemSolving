#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100000
#define INF 987654321
int N, S;
int arr[MAX_SIZE];
int dp[MAX_SIZE];
int result = INF;
void Search()
{
	int left = 0, right = 0;
	long long sum = arr[0];
	while (left <= right && right < N) {
		//조건을 만족하지 않으면, 탐색 범위를 늘린다.
		if (sum < S)
			sum += arr[++right];
		//조건을 일치하면, 정답을 갱신하고 탐색 범위를 늘린다.
		else if (sum == S) {
			result = min(result, (right - left) + 1);
			sum += arr[++right];
		}
		//조건을 초과하면, 탐색범위를 줄인다.
		else {
			result = min(result, (right - left) + 1);
			sum -= arr[left++];
		}
	}
	if (result == INF)
		printf("0\n");
	else
		printf("%d\n", result);
}
int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	Search();
	return 0;
}