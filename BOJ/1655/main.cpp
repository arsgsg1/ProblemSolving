#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;
int main()
{
	cin >> N;
	int num, mid = 0, cnt = 0;
	scanf("%d", &num);
	mid = num;
	printf("%d\n", mid);
	for (int i = 1; i < N; i++) {
		scanf("%d", &num);
		cnt++;
		if (mid <= num) {
			minq.push(num);
		}
		else {
			maxq.push(num);
		}
		int size = maxq.size();

		if (size != minq.size() && size + 1 != minq.size()) {
			if (maxq.size() > minq.size()) {
				minq.push(mid);
				mid = maxq.top();
				maxq.pop();
			}
			else {
				maxq.push(mid);
				mid = minq.top();
				minq.pop();
			}
		}
		printf("%d\n", mid);
	}
	return 0;
}