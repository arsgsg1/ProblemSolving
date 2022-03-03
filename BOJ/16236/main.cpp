#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
int N;
int field[21][21];
struct shark {
	int r, c;
	int fish, size;
};
shark sk;
struct fish {
	int r, c;
	int size;
	int dist;
};
vector<fish> fishes;
int dirRow[] = { 1, 0, -1, 0 };
int dirCol[] = { 0, 1, 0, -1 };
bool cmp(fish& f1, fish& f2)
{
	if (f1.dist == f2.dist) {
		if (f1.r == f2.r) {
			return f1.c < f2.c;
		}
		return f1.r < f2.r;
	}
	return f1.dist < f2.dist;
}
void fish_search()
{
	int visit[21][21], dist = 0;
	queue<pair<int, int>> q;
	q.push({ sk.r, sk.c });
	memset(visit, 0, sizeof(visit));
	visit[sk.r][sk.c] = 1;
	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			nr = r + dirRow[i];
			nc = c + dirCol[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (visit[nr][nc] == 0) {
				if (field[nr][nc] > sk.size)
					continue;
				q.push({ nr, nc });
				visit[nr][nc] = visit[r][c] + 1;
				if (field[nr][nc] != 0 && field[nr][nc] < sk.size)
					fishes.push_back({ nr, nc, field[nr][nc], visit[nr][nc] - 1 });
			}
		}
	}
}
void fish_eat(fish& f)
{
	sk.r = f.r;
	sk.c = f.c;
	field[f.r][f.c] = 0;
	sk.fish++;
	if (sk.fish == sk.size) {
		sk.fish = 0;
		sk.size++;
	}
}
int main()
{
	cin >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] == 9) {
				sk = { r, c, 0, 2 };
				field[r][c] = 0;
			}
		}
	int answer = 0;
	bool GameOver = false;
	while (!GameOver) {
		GameOver = true;
		fish_search();
		if (fishes.size()) {
			sort(fishes.begin(), fishes.end(), cmp);
			answer += fishes[0].dist;
			fish_eat(fishes[0]);
			fishes.clear();
			GameOver = false;
		}
	}
	printf("%d\n", answer);
	return 0;
}