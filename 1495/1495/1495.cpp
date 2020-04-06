#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool bfs[1000] = { false };
vector<int> v;
queue<int> q;
int n;

void Print(int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", bfs[i]);
	}
	printf("\n============\n");
}

int Solution(vector<int>& v, int s, int m)
{
	int cur, next, dist[2], depth = 0, result = 0;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		dist[0] = v[depth];
		dist[1] = -v[depth];
		for (int i = 0; i < 2; i++) {
			next = cur + dist[i];
			if (next >= 0 && next <= m && !bfs[next]) {
				bfs[next] = true;
				q.push(next);
				result = max(result, next);
			}
		}
		Print(n);
		depth++;
	}
	return result;
}

int main()
{
	int s, m, temp;
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	bfs[s] = true;
	q.push(s);
	printf("%d\n", Solution(v, s, m));
	return 0;
}

