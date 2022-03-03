#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100001
int N, M, A, B, C;
int Start, End, MaxWeight = 0;
vector<pair<int, int>> adj[MAX_SIZE];
bool bfs(unsigned int target)
{
	vector<bool> visit(MAX_SIZE, false);
	visit[Start] = true;
	queue<unsigned int> q;
	q.push(Start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (unsigned int i = 0; i < adj[here].size(); i++) {
			unsigned int there = adj[here][i].first;
			unsigned int weight = adj[here][i].second;
			if (visit[there] == false && weight >= target) {
				q.push(there);
				visit[there] = true;
			}
		}
	}
	if (visit[End])
		return true;
	else
		return false;
}
void BinSearch()
{
	unsigned int left = 1;
	unsigned int right = MaxWeight;
	unsigned int mid = (left + right) / 2;
	while (left <= right) {
		if (bfs(mid))
			left = mid + 1;
		else
			right = mid - 1;
		mid = (left + right) / 2;
	}
	printf("%d\n", mid);
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		MaxWeight = max(MaxWeight, C);
		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}
	scanf("%d %d", &Start, &End);
	BinSearch();
	return 0;
}