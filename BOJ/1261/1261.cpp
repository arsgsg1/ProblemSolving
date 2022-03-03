
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_LEN 101
int m[MAX_LEN][MAX_LEN];
int temp[MAX_LEN][MAX_LEN];

void Init(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = 0;
			temp[i][j] = 0;
		}
	}
}

int Solution(int n)
{
	int down = 1, right = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] == 0)
				continue;

			temp[i + down][j] = min(temp[i][j] + 1, temp[i + down][j]);
			temp[i][j + right] = min(temp[i][j] + 1, temp[i][j + right]);
			
		}
	}
	return temp[n - 1][n - 1];
}

int main()
{
	int n;
	cin >> n;
	Init(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	return 0;
}
