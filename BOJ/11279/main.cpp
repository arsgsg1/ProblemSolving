#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int N;
int main()
{
	cin >> N;
	priority_queue<int> pq;
	int num;
	for (int i = 0; i < N; i++) {
		//cin으로 하면 시간초과
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