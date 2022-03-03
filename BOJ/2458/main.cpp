#include <iostream>
using namespace std;
#define MAX_V 501
#define INF 987654321
int dist[MAX_V][MAX_V];
int N, M;
void setting(int n)
{
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dist[i][j] = INF;
		}
	}
}
void floyd(int n)
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == 1 && dist[k][j] == 1) {
					dist[i][j] = 1;
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	int a, b;
	setting(N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		dist[a][b] = 1;
	}
	floyd(N);
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		int count = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			if (dist[i][j] == 1)
				count++;
			if (dist[j][i] == 1)
				count++;
		}
		if (count == N - 1)
			answer++;
	}
	printf("%d\n", answer);
	return 0;
}