#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_LEN	1001
#define LEFT	1
#define UP		2
#define DIAG	3
int dp[MAX_LEN][MAX_LEN] = { {0, 0} };
int track[MAX_LEN][MAX_LEN] = { {0, 0} };
void PrintLCS(const string& b, int x, int y)
{
	switch (track[x][y])
	{
	case UP:
		PrintLCS(b, x - 1, y);
		break;
	case LEFT:
		PrintLCS(b, x, y - 1);
		break;
	case DIAG:
		PrintLCS(b, x - 1, y - 1);
		printf("%c", b[y]);
		break;
	default:
		return;
	}
}
void CalcLCSAndLength(const string& x, const string& y)
{
	int xLen = x.length(), yLen = y.length();
	for (int i = 1; i < xLen; i++) {
		for (int j = 1; j < yLen; j++) {
			if (x[i] == y[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				track[i][j] = DIAG;
			}
			else if (dp[i - 1][j] >= dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				track[i][j] = UP;
			}
			else {
				dp[i][j] = dp[i][j - 1];
				track[i][j] = LEFT;
			}
		}
	}
	printf("%d\n", dp[xLen - 1][yLen - 1]);
	PrintLCS(y, xLen - 1, yLen - 1);
}
int main()
{
	string x, y;
	cin >> x >> y;
	
	x.insert(0, "0");
	y.insert(0, "0");
	
	CalcLCSAndLength(x, y);
	return 0;
}