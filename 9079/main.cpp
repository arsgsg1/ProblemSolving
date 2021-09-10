#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
#define MAX_SIZE 1 << 9
int TC, answer = -1;
char arr[3][3];
int visit[MAX_SIZE];
int statArr[8][3] = { 
	{0, 1, 2}, 
	{0, 4, 8}, 
	{0, 3, 6},
	{1, 4, 7}, 
	{3, 4, 5}, 
	{2, 4, 6},
	{2, 5, 8}, 
	{6, 7, 8} };
int nextStat(int cur, int idx1, int idx2, int idx3)
{
	cur = cur ^ (1 << idx1);
	cur = cur ^ (1 << idx2);
	cur = cur ^ (1 << idx3);
	return cur;
}
void bfs(int stat)
{
	visit[stat] = 1;
	queue<int> q;
	q.push(stat);
	int next;
	answer = -1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == 0 || cur == (1 << 9) - 1) {
			answer = visit[cur] - 1;
			break;
		}
		for (int i = 0; i < 8; i++) {
			next = nextStat(cur, statArr[i][0], statArr[i][1], statArr[i][2]);
			if (visit[next] == false) {
				q.push(next);
				visit[next] = visit[cur] + 1;
			}
		}
	}
}
int main()
{
	scanf("%d", &TC);
	while (TC--) {
		int cur = 0;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				cin >> arr[i][j];
		for (int i = 0; i < 9; i++) {
			if (arr[i / 3][i % 3] == 'T')
				cur |= 1 << i;
		}
		memset(visit, 0, sizeof(visit));
		bfs(cur);
		printf("%d\n", answer);
	}
	return 0;
}