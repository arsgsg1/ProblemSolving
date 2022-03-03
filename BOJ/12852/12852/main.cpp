#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1000001
#define INF 987654321
int X;
int dp[MAX_SIZE] = { 0, };
int path[MAX_SIZE] = { 0, };
void track(int s)
{
	printf("%d ", s);
	if(s != 1)
		track(path[s]);
}
void BottomUp()
{
	dp[1] = 0;
	for (int i = 1; i <= X; i++) {
		if (i * 3 <= X && dp[i * 3] > dp[i] + 1) {
			dp[i * 3] = dp[i] + 1;
			path[i * 3] = i;
		}
		if (i * 2 <= X && dp[i * 2] > dp[i] + 1) {
			dp[i * 2] = dp[i] + 1;
			path[i * 2] = i;
		}
		if (i + 1 <= X && dp[i + 1] > dp[i] + 1) {
			dp[i + 1] = dp[i] + 1;
			path[i + 1] = i;
		}
	}
	printf("%d\n", dp[X]);
	track(X);
}
int main()
{
	fill(&dp[0], &dp[MAX_SIZE], INF);
	scanf("%d", &X);
	BottomUp();
	return 0;
}