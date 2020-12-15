#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int field[100][100] = { {0,0} };
bool AttachField[100][100] = { {true, true} };
int cnt = 0, result = 10000;
vector<int> paper = { 0, 5, 5, 5, 5, 5 };
bool IsAttach(int row, int col, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (field[row + i][col + j] == 0 ||
				AttachField[row + i][col + j] == true) {
				return false;
			}
		}
	}
	return true;
}
void AttachPaper(int row, int col, int size)
{
	--paper[size];
	++cnt;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			AttachField[row + i][col + j] = true;
		}
	}
}
void DettachPaper(int row, int col, int size)
{
	++paper[size];
	--cnt;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			AttachField[row + i][col + j] = false;
		}
	}
}
bool IsFailed()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			//1인 칸을 덮지 못했다.
			if (field[i][j] == 1 &&
				AttachField[i][j] == false) {
				return true;
			}
		}
	}
	return false;
}
bool IsFill()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (field[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}
void dfs(int row, int col)
{
	int i = row;
	int j = col;
	for (; i < 10; i++) {
		for (; j < 10; j++) {
			if (field[i][j] && AttachField[i][j] == false) {
				for (int k = 1; k <= 5; k++) {
					if (IsAttach(i, j, k)) {
						if (paper[k] > 0) {
							AttachPaper(i, j, k);
							dfs(i, j);
							DettachPaper(i, j, k);
						}
					}
					else {
						return;
					}
				}
				return;
			}
		}
		j = 0;
	}
	//1인 칸을 덮는게 실패하지 않으면, 최솟값을 갱신
	if(!IsFailed())
		result = min(cnt, result);
}
int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> field[i][j];
			AttachField[i][j] = false;
		}
	}
	if (IsFill()) {
		printf("4\n");
		return 0;
	}

	dfs(0, 0);
	
	if (result == 10000) {
		printf("-1\n");
	}
	else {
		printf("%d\n", result);
	}
	return 0;
}