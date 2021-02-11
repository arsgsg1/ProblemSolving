#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100000
int dp[MAX_SIZE][4];
int solution(vector<vector<int> > land)
{
	int answer = 0;
	int len = land.size();
	for (int i = 0; i<4; i++)
		dp[0][i] = land[0][i];
	for (int i = 1; i < len; i++) {
		dp[i][0] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][3])) + land[i][0];
		dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3])) + land[i][1];
		dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3])) + land[i][2];
		dp[i][3] = max(dp[i - 1][1], max(dp[i - 1][2], dp[i - 1][0])) + land[i][3];
	}
	for (int i = 0; i<4; i++)
		if (answer < dp[len - 1][i])
			answer = dp[len - 1][i];
	return answer;
}