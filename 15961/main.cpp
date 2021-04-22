#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;
#define MAX_SIZE 3000000
int N, D, K, C;
int arr[MAX_SIZE];
int cnt[MAX_SIZE];
deque<int> window;
int main()
{
	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int s = 0, e = 0, sum = 1;
	int answer = 0;
	cnt[C]++;
	for (int i = 0; i < K; i++) {
		if (cnt[arr[e]] == 0)
			sum++;
		cnt[arr[e]]++;
		e++;
	}
	answer = sum;
	for (int i = 0; i < N - 1; i++) {
		if (cnt[arr[e]] == 0)
			sum++;
		cnt[arr[e]]++;
		e = (e + 1) % N;
		cnt[arr[s]]--;
		if (cnt[arr[s]] == 0)
			sum--;
		s = (s + 1) % N;
		answer = max(sum, answer);
	}
	printf("%d\n", answer);
	return 0;
}