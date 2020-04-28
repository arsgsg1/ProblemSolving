/*
5427 불 (https://www.acmicpc.net/problem/5427)
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_LEN 1003
char field[MAX_LEN][MAX_LEN] = { {0, 0} };
int person[MAX_LEN][MAX_LEN] = { {0, 0} };
int width, height;

queue<pair<int, int> >fq;
queue<pair<int, int> >pq;
int dirRow[] = { 1, -1, 0 , 0 };
int dirCol[] = { 0, 0, 1, -1 };

int Solution()
{
	//bfs로 불이 먼저 이동한 후 상근이가 이동합니다
	int nr, nc, cr, cc, numFire = fq.size(), numPerson = pq.size();
	while (!pq.empty()) 
	{
		//불의 이동
		if (!fq.empty()) {
			numFire = fq.size();
			for (int k = 0; k < numFire; k++) {
				cr = fq.front().first;
				cc = fq.front().second;
				for (int i = 0; i < 4; i++) {
					nr = cr + dirRow[i];
					nc = cc + dirCol[i];
					if (nc < 0 || nr < 0 || nc >= width || nr >= height) {
						continue;
					}
					//불이 이동칸이 빈 칸이므로 옮겨붙는 경우
					if (field[nr][nc] == '.') {
						field[nr][nc] = '*';
						fq.push(make_pair(nr, nc));
					}
				}
				//Print(width, height);
				fq.pop();
			}
		}
		numPerson = pq.size();
		for (int k = 0; k < numPerson; k++) {
			//상근이의 이동
			cr = pq.front().first;
			cc = pq.front().second;
			//상근이가 가장자리에 도달하면 탈출에 성공한 것으로 봅니다.
			if (cr == 0 || cc == 0 || cr == height - 1 || cc == width - 1) {
				printf("%d\n", person[cr][cc]);
				return person[cr][cc];
			}
			for (int i = 0; i < 4; i++) {
				nr = cr + dirRow[i];
				nc = cc + dirCol[i];
				//상근이가 이동한 경로는 다시 큐에 넣지 않고, 빈 칸일 때만 넣습니다.
				if (field[nr][nc] == '.' && person[nr][nc] == false) {
					person[nr][nc] = person[cr][cc] + 1;
					pq.push(make_pair(nr, nc));
				}
			}
			pq.pop();
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> width >> height;
		for (int j = 0; j < height; j++) {
			for (int k = 0; k < width; k++) {
				cin >> field[j][k];
				if (field[j][k] == '*') {
					fq.push(make_pair(j, k));
				}
				if (field[j][k] == '@') {
					person[j][k] = true;
					pq.push(make_pair(j, k));
				}
			}
		}
		Solution();
		fill_n(&person[0][0], MAX_LEN * MAX_LEN, 0);
		while (!fq.empty()) fq.pop();
		while (!pq.empty()) pq.pop();
	}
	return 0;
}