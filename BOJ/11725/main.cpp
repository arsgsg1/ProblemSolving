#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 100001
int N;
vector<int> path[MAX_SIZE];
bool visit[MAX_SIZE];
int result[MAX_SIZE];
void dfs(int from)
{
	visit[from] = true;
	for (int i = 0; i < path[from].size(); i++) {
		int next = path[from][i];
		if (visit[next] == false) {
			result[next] = from;
			dfs(next);
		}
	}
	return;
}
int main()
{
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= N; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}