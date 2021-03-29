/*
접근
1. 문제 번호가 낮은 문제는 높은 문제보다 우선하여 풀어야 한다.
    1.1 우선순위 큐로 낮은 문제부터 먼저 꺼내도록 한다.
2. in-count가 0인 노드부터 출력
*/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define MAX_SIZE 32001
vector<int> graph[MAX_SIZE];
int N, M;
int inDegree[MAX_SIZE];
void topology_sort()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0)
			pq.push(i);
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		printf("%d ", cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (--inDegree[next] == 0)
				pq.push(next);
		}
	}
}
int main()
{
	cin >> N >> M;
	int s, e;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		inDegree[e]++;
	}
	topology_sort();
	return 0;
}