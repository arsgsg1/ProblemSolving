/*
접근
1. 줄을 세우는 과정은 묵시적 그래프로 표현 가능함
2. 특정 노드의 선행 노드가 있기 때문에 위상정렬로 나타냄
3. in-count가 0인 노드들부터 출력
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX_SIZE 32001
int N, M;
vector<int> graph[MAX_SIZE];
int inDegree[MAX_SIZE];
void topology_sort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (--inDegree[next] == 0) {
				q.push(next);
			}
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