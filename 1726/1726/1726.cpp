#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct {
	int row;
	int col;
	int dir;
}DIR;
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4
int dir[] = { EAST, WEST, SOUTH, NORTH };
int dx[] = { 0, 1, -1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };	//동서남북
int field[100][100] = { {0, 0}, };

int Solution(queue<DIR>& q, int width, int height, DIR goal)
{
	DIR cur, next;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur.row == goal.row && cur.col == goal.col) {
			//좌표에 도달했을 때
			//방향 비교
			
		}
		
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= 3; j++) {
				next.col = cur.col + dx[dir[i]] * j;
				next.row = cur.row + dy[dir[i]] * j;
				next.dir = dir[i];
				if (next.row >= width || next.col >= height || next.col < 0 || next.row < 0)
					continue;

				if (field[next.row][next.col] == 0) {
					//방향에 따른 명령횟수 증가 및 방문처리
					if (next.dir == cur.dir) {
						field[next.row][next.col] += field[cur.row][cur.col] + 1;
					}
					else {
						field[next.row][next.col] += field[cur.row][cur.col] + 2;
					}
					q.push(next);
				}
			}
		}
	}
	return 0;
}

int main()
{
	queue<DIR> q;
	DIR start, goal;
	int width, height;
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> field[i][j];
		}
	}
	cin >> start.row >> start.col >> start.dir;
	cin >> goal.row >> goal.col >> goal.dir;
	start.row--;
	start.col--;
	goal.row--;
	goal.col--;
	q.push(start);
	Solution(q, width, height, goal);
	return 0;
}