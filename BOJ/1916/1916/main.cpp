#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX_V 1001
#define INF 987654321
vector<pair<int, int>>adj[MAX_V];
int N, M;
int Start, End;
void djikstra(int start)
{
	vector<int> dist(N + 1, INF);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ start, 0 });
	dist[start] = 0;
	while (!pq.empty()) {
		int here = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push({ there, nextDist });
			}
		}
	}
	printf("%d\n", dist[End]);
}
int main()
{
	cin >> N >> M;
	int s, e, d;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> d;
		adj[s].push_back({ e, d });
	}
	cin >> Start >> End;
	djikstra(Start);
	return 0;
}