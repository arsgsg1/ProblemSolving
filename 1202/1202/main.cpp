#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 300000
pair<int, int> jew[MAX_SIZE];
int bp[MAX_SIZE];
int N, K;
int main()
{
	cin >> N >> K;
	int m, v, c;
	long long result = 0;
	priority_queue<int> pq;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		cin >> jew[i].first >> jew[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bp[i];
	}
	sort(jew, jew + N);
	sort(bp, bp + K);

	for (int i = 0; i < K; i++) {
		while (idx < N && jew[idx].first <= bp[i])
			pq.push(jew[idx++].second);
		if (pq.size()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << endl;
	return 0;
}