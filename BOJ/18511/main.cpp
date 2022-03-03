#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int K, N, answer = 0;
string number;
int arr[3];
void dfs(int toPick, int sum)
{
	if (sum > N)
		return;
	answer = max(answer, sum);
	for (int i = 0; i < K; i++) {
		dfs(toPick + 1, sum * 10 + arr[i]);
	}
}
int main()
{
	cin >> number;
	N = stoi(number);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
		scanf("%d", &arr[i]);
	dfs(0, 0);
	printf("%d\n", answer);
	return 0;
}