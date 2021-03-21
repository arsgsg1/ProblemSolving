#include <iostream>
using namespace std;
#define MAX_SIZE 2001
int N, M;
int arr[MAX_SIZE];
bool dp[MAX_SIZE][MAX_SIZE];
/*
1차원 테이블을 사용하면 이전에 구했던 팰린드롬의 길이와 겹쳐서
정보가 겹칠 수 있기 때문에 2차원을 사용해야 함
dp[N][M] = N부터 M까지 팰린드롬인지 여부
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