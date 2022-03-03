#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 987654321
#define MAX_V 1001
using namespace std;
int N, M;
int Start, End;
vector<pair<int, int>> adj[MAX_V];

void djikstra(int start)
{
	vector<int> dist(N + 1, INF);
	vector<int> path(N + 1, INF);
	dist[start] = 0;
	path[start] = 0;

	priority_queue < pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
	pq.push({ start, 0 });
	while (!pq.empty()) {
		int here = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++){
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				path[there] = here;
				pq.push({ there, nextDist });
			}
		}
	}
	int vertex = End;
	vector<int> trace;
	while (path[vertex]) {
		trace.push_back(vertex);
		vertex = path[vertex];
	}
	trace.push_back(start);
	printf("%d\n%d\n", dist[End], trace.size());
	for (int i = trace.size() - 1; i >= 0; i--) {
		printf("%d ", trace[i]);
	}
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