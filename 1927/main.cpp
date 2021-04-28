#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N;
int main()
{
	cin >> N;
	int num;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		if (num == 0) {
			if (pq.size()) {
				printf("%d\n", pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
		else {
			pq.push(num);
		}
	}
	return 0;
}