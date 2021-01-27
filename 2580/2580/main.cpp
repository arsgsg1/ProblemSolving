#include <iostream>
#include <map>
using namespace std;
#define MAX_SIZE 9
map<int, int> m[3][3];
int arr[MAX_SIZE][MAX_SIZE];
int cnt = 0;
void print()
{
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
bool isPushable(int row, int col, int num)
{
	for (int i = 0; i < 9; i++) {
		int target = arr[i][col];
		if (target == num)
			return false;
	}
	for (int i = 0; i < 9; i++) {
		int target = arr[row][i];
		if (target == num)
			return false;
	}
	if (m[row / 3][col / 3].find(num) != m[row / 3][col / 3].end())
		return false;
	
	return true;
}
void dfs(int row, int col, int toPick)
{
	if (toPick == 0) {
		print();
		exit(0);
	}
	int i = row, j = col;
	for (; i < MAX_SIZE; i++) {
		for (; j < MAX_SIZE; j++) {
			if (arr[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					if (isPushable(i, j, k)) {
						arr[i][j] = k;
						m[i / 3][j / 3].insert({ k, 1 });
						dfs(i, j, toPick - 1);
						arr[i][j] = 0;
						m[i / 3][j / 3].erase(k);
					}
				}
				return;
			}
		}
		j = 0;
	}
}
int main()
{
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
				cnt++;
			m[i / 3][j / 3].insert({ arr[i][j], 1 });
		}
	}
	dfs(0, 0, cnt);
	return 0;
}