#include <iostream>
using namespace std;
#define MAX_SIZE 2001
int N, M;
int arr[MAX_SIZE];
bool dp[MAX_SIZE][MAX_SIZE];
/*
1���� ���̺��� ����ϸ� ������ ���ߴ� �Ӹ������ ���̿� ���ļ�
������ ��ĥ �� �ֱ� ������ 2������ ����ؾ� ��
dp[N][M] = N���� M���� �Ӹ�������� ����
*/
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		dp[i][i] = true;
	}
	for (int i = 1; i <= N; i++) { 
		dp[i][i] = true; 
		if (arr[i] == arr[i - 1]) { 
			dp[i - 1][i] = true; 
		} 
	}

	for (int i = 2; i < N; i++) {
		for (int j = 1; j <= N - i; j++) {
			if (arr[j] == arr[i + j] && dp[j + 1][j + i - 1]) {
				dp[j][i + j] = true;
			}
		}
	}
	cin >> M;
	int s, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		printf("%d\n", dp[s][e]);
	}
	return 0;
}