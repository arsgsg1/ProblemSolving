#include <iostream>
using namespace std;
int S, N;
int arr[20];
int answer = 0;
void bf(int n, int sum, int toPick, int idx)
{
	if (toPick == 0) {
		if (sum == S)
			answer++;
		return;
	}
	for (int next = idx; next < n; next++) {
		sum += arr[next];
		bf(n, sum, toPick - 1, next + 1);
		sum -= arr[next];
	}
}
int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	for (int n = 1; n <= N; n++) {
		bf(N, 0, n, 0);
	}
	printf("%d\n", answer);
	return 0;
}