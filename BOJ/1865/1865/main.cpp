#include <cstdio>
#include <vector>
using namespace std;

struct SET {
	int v, w;
};
const int MAX = 501;
const int INF = 1e9;
int n, m, w;

void solve_bf(vector<int> bf, vector<SET> graph[MAX]) {
	bf[1] = 0;
	for (int iter = 0; iter < n; iter++) {
		for (int v = 1; v <= n; v++) {
			for (int i = 0; i < graph[v].size(); i++) {
				int nv = graph[v][i].v;
				int nw = graph[v][i].w;
				if (bf[nv] > bf[v] + nw) {
					bf[nv] = bf[v] + nw;
					if (iter == n - 1) {
						printf("YES\n");
						return;
					}
				}
			}
		}
	}
	printf("NO\n");
	return;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &n, &m, &w);
		vector<SET> graph[MAX];
		vector<int> bf(n + 1, INF);
		int s, e, t;
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back({ e, t });
			graph[e].push_back({ s, t });
		}
		for (int j = 0; j < w; j++) {
			scanf("%d %d %d", &s, &e, &t);
			graph[s].push_back({ e, -t });
		}
		solve_bf(bf, graph);
	}
	return 0;
}