#include <iostream>
#include <queue>
using namespace std;
int dirRow[] = { 0, 1, -1, 0, 0 };
int dirCol[] = { 0, 0, 0, 1, -1 };
int bfs[5][102][102] = { {false, false, false} };
int field[102][102];
int row, col;
typedef struct {
	int row;
	int col;
	int dir;
}_TERM;

int Solution(queue<_TERM>& q, const _TERM& goal)
{
	_TERM term, next;
	while (!q.empty())
	{
		term = q.front();
		q.pop();
		if (goal.row == term.row && goal.col == term.col && goal.dir == term.dir) {
			return bfs[goal.dir][goal.row][goal.col] - 1;
		}
		//Go
		for (int i = 1; i <= 3; i++) {
			next.row = term.row + dirCol[term.dir] * i;
			next.col = term.col + dirRow[term.dir] * i;
			next.dir = term.dir;
			if (next.row < 1 || next.col < 1 ||
				next.row > row || next.col > col ||
				field[next.row][next.col] != 0) {
				//범위를 벗어나거나 벽을 통과할순 없으므로 중단
				break;
			}
			if (bfs[next.dir][next.row][next.col] == 0) {
				q.push(next);
				bfs[next.dir][next.row][next.col] = bfs[term.dir][term.row][term.col] + 1;
			}
		}
		//Turn Direction
		for (int i = 1; i <= 4; i++) {
			if (bfs[i][term.row][term.col] == 0) {
				next.row = term.row;
				next.col = term.col;
				next.dir = i;
				q.push(next);
				//방향에 따른 명령 횟수 증가
				if ((term.dir == 1 && i == 2) || (term.dir == 3 && i == 4)) {
					//반대방향
					bfs[next.dir][next.row][next.col] = bfs[term.dir][term.row][term.col] + 2;
				}
				else {
					//수직방향
					bfs[next.dir][next.row][next.col] = bfs[term.dir][term.row][term.col] + 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	_TERM term;
	queue<_TERM> q;
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> field[i][j];
		}
	}
	cin >> term.row >> term.col >> term.dir;
	bfs[term.dir][term.row][term.col] = 1;
	q.push(term);
	cin >> term.row >> term.col >> term.dir;
	printf("%d\n", Solution(q, term));
	return 0;
}