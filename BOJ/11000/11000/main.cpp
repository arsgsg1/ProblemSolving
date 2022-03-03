#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;
int N;
bool cmp(pair<int, int>& p1, pair<int, int>& p2)
{
	if (p1.first == p2.first)
		return p1.second > p2.second;
	else
		return p1.first > p2.first;
}
int main()
{
	scanf("%d", &N);
	vector<pair<int, int>> times;
	int s, e;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &s, &e);
		times.push_back({ s, e });
	}
	sort(times.begin(), times.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(times[0].second);
	for (int i = 1; i < N; i++) {
		if (pq.top() <= times[i].first)
			pq.pop();
		pq.push(times[i].second);
	}
	cout << pq.size();
	return 0;
}