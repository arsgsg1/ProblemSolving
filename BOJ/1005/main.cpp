#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX_SIZE 10001
int N, K;
int dur[MAX_SIZE];
int inDegree[MAX_SIZE];
int result[MAX_SIZE];
vector<int> graph[MAX_SIZE];
void topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		//in-count가 0인 노드들을 큐에 넣는다.
		if (inDegree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			//현재까지 찾은 최댓값보다 지금 값이 더 크다면 갱신
			result[next] = max(result[next], result[cur] + dur[cur]);
			//다시 in-count가 0인 노드들을 큐에 넣음
			if (--inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}
int main()
{
	int tc, s, e, goal;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		cin >> N >> K;
		memset(dur, 0, sizeof(dur));
		memset(result, 0, sizeof(result));
		memset(inDegree, 0, sizeof(inDegree));
		for (int i = 1; i <= N; i++) {
			cin >> dur[i];
			graph[i].clear();
		}
		for (int i = 1; i <= K; i++) {
			cin >> s >> e;
			graph[s].push_back(e);
			inDegree[e]++;
		}
		cin >> goal;
		topology_sort();
		printf("%d\n", result[goal] + dur[goal]);
	}
	return 0;
}