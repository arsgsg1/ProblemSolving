#include <iostream>
#include <algorithm>
#include <queue>
#define MAX_LEN 101
int m[MAX_LEN][MAX_LEN] = { 0 };
long long temp[MAX_LEN][MAX_LEN];
using namespace std;

//void Print(int n, int x, int y)
//{
//	static int step = 0;
//	printf("step [%d], x, y: [%d, %d]\n", ++step, x, y);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%d ", temp[i][j]);
//		}
//		printf("\n");
//	}
//}

void Init(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m[i][j] = 0;
			temp[i][j] = 0;
		}
	}
	temp[0][0] = 1;
}

long long Solution(int n)
{
	int dist = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] == 0 || m[i][j] == 0)
				continue;

			dist = m[i][j];
			if (i + dist < n)
				temp[i + dist][j] += temp[i][j];
			if (j + dist < n)
				temp[i][j + dist] += temp[i][j];

			//Print(n, i, j);
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
	printf("%llu\n", Solution(n));
	return 0;
}