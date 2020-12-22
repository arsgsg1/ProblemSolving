#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_SIZE 101
#define INF 987654321
int N, M, T[MAX_SIZE] = { 0, }, R;
int dist[MAX_SIZE][MAX_SIZE] = { {0,0} };
int ans = 0;
void setting()
{
	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			if(i != j)
				dist[i][j] = INF;
		}
	}
}
void floyd()
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
	}
	setting();
	for (int i = 0; i < R; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		dist[s][e] = d;
		dist[e][s] = d;
	}
	floyd();
	for (int i = 1; i <= N; i++) {
		int sum = T[i];
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			if(dist[i][j] <= M)
				sum += T[j];
		}
		ans = max(sum, ans);
	}
	printf("%d\n", ans);
	return 0;
}