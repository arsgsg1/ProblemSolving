#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

const int INF = 987654321;
const int MAX = 1000 + 1;

int N, M, X;
vector<pair<int, int>> graph[MAX];

vector<int> dijkstra(int start, int vertex)
{
	vector<int> distance(vertex, INF);
	distance[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (distance[cur] < cost)
			continue;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int neighbor = graph[cur][i].first;
			int neighborDistance = cost + graph[cur][i].second;

			if (distance[neighbor] > neighborDistance)
			{
				distance[neighbor] = neighborDistance;
				pq.push({ neighborDistance, neighbor });
			}
		}
	}

	return distance;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start].push_back({ end, cost });
	}

	int result = -1;
	for (int i = 1; i <= N; i++)
	{
		vector<int> temp = dijkstra(i, N + 1);
		vector<int> temp2 = dijkstra(X, N + 1);

		if (temp[X] + temp2[i] >= INF || temp[X] + temp2[i] < 0)
			continue;
		result = max(result, temp[X] + temp2[i]);
	}
	cout << result << "\n";
	return 0;
}