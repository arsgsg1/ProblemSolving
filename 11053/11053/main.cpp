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
	//�׻� dp�迭�� ���� �ִ� ���� ���������� �ʴ´�.
	//dp �迭�� ��򰡿� �����Ѵ�.
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