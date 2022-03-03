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
		//in-count�� 0�� ������ ť�� �ִ´�.
		if (inDegree[i] == 0)
			q.push(i);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			//������� ã�� �ִ񰪺��� ���� ���� �� ũ�ٸ� ����
			result[next] = max(result[next], result[cur] + dur[cur]);
			//�ٽ� in-count�� 0�� ������ ť�� ����
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