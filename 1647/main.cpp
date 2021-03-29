#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_SIZE 100001
int N, M;
int parents[MAX_SIZE];
struct Edge {
	int from, to;
	int cost;
};
vector<Edge> v;
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
bool cmp(Edge& e1, Edge& e2)
{
	return e1.cost < e2.cost;
}
int main()
{
	cin >> N >> M;
	Edge ed;
	int s, e, d, cnt = 0;
	long long answer = 0;
	for (int i = 0; i <= N; i++)
		parents[i] = i;
	for (int i = 0; i < M; i++) {
		cin >> s >> e >> d;
		ed = { s, e, d };
		v.push_back(ed);
	}
	sort(v.begin(), v.end(), cmp);
	for (const auto& e : v) {
		if (!find(e.from, e.to)) {
			_union(e.from, e.to);
			answer += e.cost;
			cnt++;
			if (cnt == N - 2)
				break;
		}
	}
	printf("%lld\n", answer);
	return 0;
}