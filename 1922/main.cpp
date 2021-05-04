#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_V 1001
int N, M;
int parents[MAX_V];
int get_parent(int x)
{
	if (parents[x] == x)
		return x;
	return parents[x] = get_parent(parents[x]);
}
void _union(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a < b)
		parents[b] = a;
	else
		parents[a] = b;
}
bool find(int a, int b)
{
	a = get_parent(a);
	b = get_parent(b);
	if (a == b)
		return true;
	else
		return false;
}
void setting()
{
	for (int i = 1; i <= N; i++)
		parents[i] = i;
}
int main()
{
	cin >> N >> M;
	int s, e, d, answer = 0;
	setting();
	vector<pair<int, pair<int, int>>> edges;
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &s, &e, &d);
		edges.push_back({ d, {s, e} });
		edges.push_back({ d, {e, s} });
	}
	sort(edges.begin(), edges.end());
	for (const auto& edge : edges) {
		s = edge.second.first;
		e = edge.second.second;
		d = edge.first;
		if (!find(s, e)) {
			_union(s, e);
			answer += d;
		}
	}
	printf("%d\n", answer);
	return 0;
}