#include <iostream>
using namespace std;
#define MAX_SIZE 31
int H, N;
long long dp[MAX_SIZE][MAX_SIZE];
int main()
{
	cin >> H >> N;
	if (H == N) { cout << 1; return 0; }
	//���� ��ǥ -> ū ��ǥ�� �����ϱ� ����
	if (H > N) swap(H, N);
	//���� -> �����ʸ����� ���� ����� ���� 1����
	//bottom up�� ����
	for (int i = H; i <= N; i++) {
		dp[H][i] = 1;
	}
	for (int i = H + 1; i <= N; i++) {
		for (int j = H + 1; j <= N; j++) {
			//����, ���ʿ��� ���� ����� �� ���
			if (i <= j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	cout << dp[N][N];
	return 0;
}