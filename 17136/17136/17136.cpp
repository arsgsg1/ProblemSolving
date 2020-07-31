#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10;
bool bPaper[10][10] = { {false, false} };
int Field[10][10] = { {0, 0} };
int Papers[] = { 0, 0, 0, 0, 0, 0 };
int ResultCount = 0, MinCount = 987654321;

void AttachPaper(const int& row, const int& col, const int& s, const bool& isAttach)
{
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			bPaper[row + i][col + j] = isAttach;
		}
	}
}

bool IsAttach(const int& row, const int& col, const int& s)
{
	//종이 크기 확인
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			if (bPaper[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int row, int col, int attachCount)
{

	for (int i = row; i < MAX; i++) {
		for (int j = col; j < MAX; j++) {
			//1. 배열을 돌면서 현재 칸이 1인지 탐색
			if (Field[i][j]) {
				//2. 현재 칸이 1이면 종이를 붙일 수 있는지 확인
				for (int k = 1; k <= 5; k++) {
					if (IsAttach(i, j, k)) {
						//3. 종이를 붙임
						AttachPaper(i, j, k, true);
						Papers[k]++;
						//재귀 진행
						dfs(i, j, attachCount + 1);
						Papers[k]--;
						//4. 종이 제거
						AttachPaper(i, j, k, false);
					}
				}
			}
		}
	}
}

int main()
{

	return 0;
}