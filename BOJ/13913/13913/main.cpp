#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_SIZE 100001
#define INF 987654321
int N, K;
int dist[MAX_SIZE];
int path[MAX_SIZE];
int nextPos(int idx, int num)
{
	switch (idx)
	{
	case 0:
		return num + 1;
	case 1:
		return num - 1;
	case 2:
		return num * 2;
	}
}
void trace(int idx)
{
	if (path[idx] == idx) {
		printf("%d ", idx);
		return;
	}
	trace(path[idx]);
	printf("%d ", idx);
}
int main()
{
	//N > K : »©±â¸¸ ÇÏ¸é µÊ
	//N == K : ¹Ù·Î Á¾·á
	//N < K : bfs
	queue<int> q;
	scanf("%d %d", &N, &K);
	fill(&dist[0], &dist[MAX_SIZE], INF);
	fill(&path[0], &path[MAX_SIZE], -1);
	dist[N] = 0;
	path[N] = N;
	if (N == K) {
		printf("0\n");
		printf("%d\n", N);
		return 0;
	}
	else if (N > K) {
		while (N > K) {
			dist[N - 1] = dist[N] + 1;
			path[N - 1] = N;
			N--;
		}
	}
	else {
		q.push(N);
		int next;
		while (!q.empty()) {
			int cur = q.front();
			if (cur == K) 
				break;
			q.pop();
			for (int i = 0; i < 3; i++) {
				next = nextPos(i, cur);
				if (next < 0 || next >= MAX_SIZE)
					continue;
				if (dist[cur] + 1 < dist[next]) {
					dist[next] = dist[cur] + 1;
					path[next] = cur;
					q.push(next);
				}
			}
		}
	}
	printf("%d\n", dist[K]);
	trace(K);
	return 0;
}