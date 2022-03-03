#include <iostream>
using namespace std;
#define INF 987654321
long long result = INF;
long long A, B;

void dfs(long long num, long long cnt)
{
	if (num > B) return;
	if (num == B) {
		result = cnt;
		return;
	}
	dfs(num * 2, cnt + 1);
	dfs(num * 10 + 1, cnt + 1);
}
int main()
{
	cin >> A >> B;
	if (A == B) {printf("0\n"); return 0;}
	dfs(A, 0);
	printf("%lld\n", result == INF ? -1 : result + 1);
	return 0;
}