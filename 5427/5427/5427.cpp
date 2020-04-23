#include <iostream>
#include <queue>
#include <cstring>
#define MAX_LEN 1003
using namespace std;
char field[MAX_LEN][MAX_LEN] = { {0,0} };
int width, height;
bool fire[MAX_LEN][MAX_LEN] = { {0,0} };
int person[MAX_LEN][MAX_LEN] = { {0,0} };
queue<pair<int, int>> fq, pq;
int dirRow[] = { 1, -1, 0, 0 };
int dirCol[] = { 0, 0, 1, -1 };

int Solution()
{
	int nextRow, nextCol;
	while (!pq.empty())
	{
		if (!fq.empty()) {
			for (int i = 0; i < 4; i++) {
				nextRow = fq.front().first + dirRow[i];
				nextCol = fq.front().second + dirCol[i];
				if (nextRow < 0 || nextCol < 0 || nextRow >= height || nextCol >= width) {
					continue;
				}
				if (field[nextRow][nextCol] != '#' && fire[nextRow][nextCol] == false) {
					fire[nextRow][nextCol] = true;
					fq.push(make_pair(nextRow, nextCol));
				}
			}
			fq.pop();
		}
		for (int i = 0; i < 4; i++) {
			nextRow = pq.front().first + dirRow[i];
			nextCol = pq.front().second + dirCol[i];
			if (nextRow < 0 || nextCol < 0 || nextRow == height || nextCol == width) {
				printf("%d\n", person[pq.front().first][pq.front().second] + 1);
				return person[pq.front().first][pq.front().second] + 1;
			}
			if (field[nextRow][nextCol] != '#' && fire[nextRow][nextCol] == false &&
				person[nextRow][nextCol] == false) {
				person[nextRow][nextCol] = person[pq.front().first][pq.front().second] + 1;
				pq.push(make_pair(nextRow, nextCol));
			}
		}
		pq.pop();
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
					fire[j][k] = true;
					fq.push(make_pair(j, k));
				}
				if (field[j][k] == '@'){
					pq.push(make_pair(j, k));
				}
			}
		}
		Solution();
		fill(&fire[0][0], &fire[height - 1][width], 0);
		fill(&person[0][0], &person[height - 1][width], 0);
		while (!fq.empty()) fq.pop();
		while (!pq.empty()) pq.pop();
	}
	return 0;
}

