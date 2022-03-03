#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 10001
int V, E;
int parents[MAX_SIZE];
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
struct Edge {
	int from, to;
	int cost;
};
bool cmp(Edge& e1, Edge& e2)
{
	return e1.cost < e2.cost;
}
int main()
{
	cin >> V >> E;
	int s, e, d, answer = 0;
	vector<Edge> v;
	for (int i = 0; i < MAX_SIZE; i++)
		parents[i] = i;
	for (int i = 0; i < E; i++) {
		cin >> s >> e >> d;
		Edge ed;
		ed = { s, e, d };
		v.push_back(ed);
		ed = { e, s, d };
		v.push_back(ed);
	}
	sort(v.begin(), v.end(), cmp);
	for (const auto& e : v){
		if (!find(e.from, e.to)) {
			_union(e.from, e.to);
			answer += e.cost;
		}
	}
	printf("%d\n", answer);
	return 0;
}