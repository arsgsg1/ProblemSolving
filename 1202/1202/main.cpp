#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 300000
pair<int, int> jew[MAX_SIZE];
int bp[MAX_SIZE] = { 0, };
int N, K;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> jew[i].first >> jew[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bp[i];
	}
	
	//무게 제한이 낮은 가방이 가장 비싼 보석을 넣도록 정렬
	sort(jew, jew + N);
	sort(bp, bp + K);

	long long result = 0;
	int idx = 0;
	priority_queue<int> pq;

	for (int i = 0; i < K; i++) {
		//
		while (idx < N && jew[idx].first <= bp[i])
			pq.push(jew[idx++].second);

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}
	cout << result;
	return 0;
}