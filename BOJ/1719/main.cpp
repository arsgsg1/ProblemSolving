#include <iostream>
using namespace std;
#define MAX_SIZE 201
#define INF 987654321
int N, M;
int dist[MAX_SIZE][MAX_SIZE];
int answer[MAX_SIZE][MAX_SIZE];
//최단거리 갱신을 위한 초기화
void setting()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			dist[i][j] = INF;
		}
	}
}
void floyd()
{
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j)
					continue;
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					answer[i][j] = answer[i][k]; //시작 지점 갱신
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int main()
{
	cin >> N >> M;
	setting();
	for (int i = 0; i < M; i++) {
		int s, e, d;
		scanf("%d %d %d", &s, &e, &d);
		dist[s][e] = d;
		answer[s][e] = e;
		dist[e][s] = d;
		answer[e][s] = s;
	}
	floyd();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				printf("- ");
			else
				printf("%d ", answer[i][j]);
		}
		printf("\n");
	}
	return 0;
}