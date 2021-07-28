/*
https://jdselectron.tistory.com/51 �̺� �׷��� ���� ����
������ �� �������� ���� �� ������ �������� ������� �ʵ��� �ϴ� ���� Ȯ���ϱ� ���ؼ�
�� �������� ������ �������� ǥ��(1 �Ǵ� 2 ���)�Ͽ� �����ϵ��� ��
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define MAX_V 20001
vector<int> graph[MAX_V];
int color[MAX_V];
int V, E;
bool cmpColor()
{
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int next = graph[i][j];
			if (color[i] == color[next])
				return false;
		}
	}
	return true;
}
void dfs(int n, int c)
{
	color[n] = c;
	for (int i = 0; i < graph[n].size(); i++) {
		int next = graph[n][i];
		if (color[next] == 0) {
			dfs(next, 3 - c);
		}
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int s, e;
		scanf("%d %d", &V, &E);
		for (int i = 1; i <= V; i++)
			graph[i].clear();
		memset(color, 0, sizeof(color));
		for (int i = 0; i < E; i++) {
			scanf("%d %d", &s, &e);
			graph[s].emplace_back(e);
			graph[e].emplace_back(s);
		}
		for (int i = 1; i <= V; i++) {
			if (color[i] == 0) {
				dfs(i, 1);
			}
		}
		if (cmpColor())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}