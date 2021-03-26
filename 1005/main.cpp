#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX_SIZE = 10001;
int N, K;
vector<int> graph[MAX_SIZE + 1];
int dur[MAX_SIZE + 1];
int inDegree[MAX_SIZE + 1];
long long result[MAX_SIZE + 1];
void topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			result[next] = max(result[next], result[cur] + dur[cur]);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}
int main()
{
	int tc;
	int s, e, goal;
	cin >> tc;
	while (tc--) {
		cin >> N >> K;
		memset(inDegree, 0, sizeof(inDegree));
		memset(result, 0, sizeof(result));
		memset(dur, 0, sizeof(dur));
		for (int i = 1; i <= N; i++)
			graph[i].clear();
		for (int i = 1; i <= N; i++)
			cin >> dur[i];
		for (int i = 1; i <= K; i++) {
			cin >> s >> e;
			inDegree[e]++;
			graph[s].push_back(e);
		}
		cin >> goal;
		topology_sort();
		printf("%d\n", result[goal] + dur[goal]);
	}
	return 0;
}