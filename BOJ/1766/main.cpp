/*
����
1. ���� ��ȣ�� ���� ������ ���� �������� �켱�Ͽ� Ǯ��� �Ѵ�.
    1.1 �켱���� ť�� ���� �������� ���� �������� �Ѵ�.
2. in-count�� 0�� ������ ���
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