#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 20
int R, C;
char field[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
int dirRow[] = { 1, -1, 0, 0 };
int dirCol[] = { 0, 0, 1, -1 };
int Max = 0;
vector<char> vc;

void Search(int r, int c)
{
	int nr, nc;
	dp[r][c] = max(dp[r][c], (int)vc.size());
	for (int i = 0; i < 4; i++) {
		nr = r + dirRow[i];
		nc = c + dirCol[i];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C)
			continue;
		if (find(vc.begin(), vc.end(), field[nr][nc]) == vc.end()) {
			vc.push_back(field[nr][nc]);
			Search(nr, nc);
		}
	}

	vc.pop_back();
	return;
}

int main()
{
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> field[i][j];
		}
	}
	vc.push_back(field[0][0]);
	Search(0, 0);
	int Max = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			Max = max(Max, dp[i][j]);
		}
	}
	printf("%d\n", Max);
	return 0;
}
