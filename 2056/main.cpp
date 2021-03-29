#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 10001
int N;
int inDegree[MAX_SIZE];
int time[MAX_SIZE];
int result[MAX_SIZE];
vector<int> graph[MAX_SIZE];
bool topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			result[next] = max(result[next], result[cur] + time[next]);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
	return true;
}
int main()
{
	cin >> N;
	int s, e, m;
	for (int e = 1; e <= N; e++) {
		cin >> time[e];
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> s;
			inDegree[e]++;
			graph[s].push_back(e);
		}
	}
	topology_sort();
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(result[i], answer);
	}
	printf("%d\n", answer);
	return 0;
}