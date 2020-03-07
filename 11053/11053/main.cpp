#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_LEN 1001
int arr[MAX_LEN] = { 0, };
int dp[MAX_LEN] = { 0, };

void Print(int n, int *arr)
{
	for (int i = 1; i <= n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int Solution(int n, int* arr)
{
	int SubMax = 0, Max = 0;
	for (int i = 1; i <= n; i++) {
		printf("step [%d]\n", i);
		Print(n, dp);
		for (int j = 0; j < i; j++) {
			printf("Compare to pre [%d], cur [%d]\n", arr[j], arr[i]);
			if (arr[j] < arr[i]) {
				SubMax = max(dp[j], SubMax);
				printf("SubMax [%d]\n", SubMax);
			}
		}
		dp[i] = SubMax + 1;
		Max = max(Max, dp[i]);
	}
	//항상 dp배열의 끝에 최대 값이 존재하지는 않는다.
	//dp 배열의 어딘가에 존재한다.
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