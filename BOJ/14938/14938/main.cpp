#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 987654321
#define MAX_SIZE 101
int N, M, R;
int item[MAX_SIZE];
int field[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE];
int answer = 0;
void setting()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j)
				field[i][j] = 0;
			else
				field[i][j] = INF;
		}
	}
}
void floyd(int n)
{
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (field[i][j] > field[i][k] + field[k][j]) {
					field[i][j] = field[i][k] + field[k][j];
				}
			}
		}
	}
}
int dfs(int cur, int dist)
{
	int sum = 0;
	if (visit[cur] == false) {
		visit[cur] = true;
		sum = item[cur];
		for (int i = 1; i <= N; i++) {
			if (cur == i)
				continue;
			else if(dist >= field[cur][i]){
				sum += dfs(i, dist - field[cur][i]);
			}
		}
	}
	return sum;
}
int main()
{
	cin >> N >> M >> R;
	setting();
	for (int i = 1; i <= N; i++)
		scanf("%d", &item[i]);
	for (int i = 1; i <= R; i++) {
		int s, e, d;
		cin >> s >> e >> d;
		field[s][e] = d;
		field[e][s] = d;
	}
	floyd(N);
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		answer = max(answer, dfs(i, M));
	}
	
	printf("%d\n", answer);
	return 0;
}