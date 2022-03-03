#include <iostream>
#include <queue>
#include <map>
#include <string.h>
using namespace std;
#define MAX_SIZE 20001
#define INF 0x7fffff
int TC, N;
int visit[MAX_SIZE] = { 0, };
vector<pair<int, int>> graph[MAX_SIZE]; //first: ¸ñÀûÁö, second: cost
int bfs(int start)
{
	int total = 0, cur, next, cost;
	queue<int> q;
	visit[start] = 0;
	q.push(start);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		vector<pair<int, int>>& v = graph[cur];
		for (const auto& p : v) {
			next = p.first;
			cost = p.second;
			if (visit[next] == 0) {
				visit[next] = visit[cur] + cost;
				q.push(next);
			}
		}
	}
	for (int n = 1; n <= N; n++) {
		if (start == n)
			continue;
		total += visit[n];
	}
	return total;
}
int main()
{
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		int s, e, d, answer = INF, count = 1;
		for (int i = 0; i < N - 1; i++) {
			scanf("%d %d %d", &s, &e, &d);
			graph[s].push_back({ e, d });
			graph[e].push_back({ s, d });
		}
		for (int n = 1; n <= N; n++) {
			memset(visit, 0, sizeof(visit));
			int sum = bfs(n);
			//printf("[%d %d] \n",n, sum);
			if(sum == answer)
				count++;
			else if(sum < answer){
				count = 1;
				answer = sum;
			}
		}
		printf("#%d %d %d\n", tc, count, answer);
		//Clear
		for (int i = 0; i < N; i++)
			graph[i].clear();
	}
	return 0;
}