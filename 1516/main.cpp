#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 501;
int N;
int inDegree[MAX_SIZE];
int dur[MAX_SIZE];
int result[MAX_SIZE];
vector<int> graph[MAX_SIZE];
void topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			result[next] = max(result[next], result[node] + dur[node]);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}
int main()
{
	cin >> N;
	int time = 0, node;
	for (int i = 1; i <= N; i++) {
		node = 0;
		cin >> time;
		dur[i] = time;
		while (1) {
			cin >> node;
			if (node == -1) break;
			graph[node].push_back(i);
			inDegree[i]++;
		}
	}
	topology_sort();
	for (int i = 1; i <= N; i++)
		printf("%d\n", result[i] + dur[i]);
	return 0;
}