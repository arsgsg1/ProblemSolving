#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MASK 0xFFFF
#define INF 987654321
int N, M;
int problem;
int answer = INF;
int ps[11];
void dfs(int sum, int idx, int cnt)
{
	if (idx == M) {
		if (sum == problem)
			answer = min(answer, cnt);
		return;
	}
	dfs(sum, idx + 1, cnt);
	sum |= ps[idx];
	dfs(sum, idx + 1, cnt + 1);
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		problem += MASK & (1 << i);
	for (int i = 0; i < M; i++) {
		int p, temp;
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> temp;
			ps[i] += MASK & (1 << temp - 1);
		}
	}
	dfs(0, 0, 0);
	if (answer == INF)
		printf("-1\n");
	else
		printf("%d\n", answer);
	return 0;
}