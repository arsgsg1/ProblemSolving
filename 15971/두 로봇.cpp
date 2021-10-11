/*
BFS: �� ������ �ֺ� ������ Ž���ϱ� ������ �ּڰ��� �ڸ���.
���� �������� ���� ��ο� �ִ����� Ȯ���ϱ� ����, �ֺ� ������ �ٸ� �ʿ��� �湮�ƴ����� Ȯ��.
Ʋ�� ����: �ִ� ��� ���̿� �ִ� �� ���� �ո� ���ϴ°� �ƴϾ��� ������ Ʋ��.

���� ���ϴ� ����
1. �ִ� ����� ����ġ �� - ���� �� ����ġ�ΰ� �ľ�.
2. Ž�� ��� ����: dfs, bfs, ���ͽ�Ʈ�� �� �� �ϳ� ����
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_V 100001
#define INF 1e9
vector<pair<int, int>> graph[MAX_V];
int dist[MAX_V];
bool visited[MAX_V];
int N, Start, End, answer = INF;
void dfs(int cur, int sum, int max_w)
{
	if (cur == End) {
		answer = sum - max_w;
		return;
	}
	visited[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i].first;
		int nextCost = sum + graph[cur][i].second;
		if (visited[next] == false) {
			dfs(next, nextCost, max(max_w, graph[cur][i].second));
		}
	}
}
int main()
{
	cin >> N >> Start >> End;
	int s, e, d;
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d %d", &s, &e, &d);
		graph[s].push_back({ e, d });
		graph[e].push_back({ s, d });
	}
	dfs(Start, 0, 0);
	printf("%d\n", answer);
	return 0;
}