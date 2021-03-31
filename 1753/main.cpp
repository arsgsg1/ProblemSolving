#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define INF 987654321
int V, E;
int Start;
vector<pair<int, int>> graph[20001];
int dist[20001];
void djikstra(int start)
{
	priority_queue<pair<int, int>,
		vector<pair<int, int>>,
		greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (dist[cur] < cost)
			continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextCost = graph[cur][i].second + dist[cur];
			if (dist[next] > nextCost) {
				dist[next] = nextCost;
				pq.push({ nextCost, next });
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	cin >> Start;
	int s, e, d;
	for (int i = 0; i <= V; i++)
		dist[i] = INF;
	dist[Start] = 0;
	for (int i = 0; i < E; i++) {
		cin >> s >> e >> d;
		graph[s].push_back({ e, d });
	}
	djikstra(Start);
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}