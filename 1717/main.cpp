#include <iostream>
using namespace std;
#define MAX_V 1000001
int N, M;
int parents[MAX_V];
void setting(int n)
{
	for (int i = 0; i <= n; i++)
		parents[i] = i;
}
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
int main()
{
	int kind = 0, a, b;
	cin >> N >> M;
	setting(N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &kind, &a, &b);
		if (kind == 0) {
			if (!find(a, b)) {
				_union(a, b);
			}
		}
		else if (kind == 1) {
			if (find(a, b)) {
				printf("YES\n");
			}
			else {
				printf("NO\n");
			}
		}
	}
	return 0;
}