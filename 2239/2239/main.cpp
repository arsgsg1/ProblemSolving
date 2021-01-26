#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
#define MAX_SIZE 9
map<int, int> m[3][3];
int arr[MAX_SIZE][MAX_SIZE];
int cnt = 0;
bool isPushable(int row, int col, int num)
{
	for (int i = 0; i < MAX_SIZE; i++) {
		if (arr[row][i] != 0 && arr[row][i] == num) {
			return false;
		}
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		if (arr[i][col] != 0 && arr[i][col] == num) {
			return false;
		}
	}
	if (m[row / 3][col / 3].find(num) != m[row / 3][col / 3].end()) {
		return false;
	}
	return true;
}
void print()
{
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
void dfs(int row, int col, int toPick)
{
	if (toPick == 0) {
		print();
		exit(0);
	}
	int i = row;
	int j = col;
	for (; i < MAX_SIZE; i++) {
		for (; j < MAX_SIZE; j++) {
			if (arr[i][j] == 0) {
				for (int k = 1; k <= MAX_SIZE; k++) {
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
	string str;
	for (int i = 0; i < MAX_SIZE; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 0)
				cnt++;
			m[i / 3][j / 3].insert({ arr[i][j], 1 });
		}
	}
	dfs(0, 0, cnt);
	return 0;
}