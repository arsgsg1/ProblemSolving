#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0, first, second, sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (const auto& item : scoville)
		pq.push(item);

	while (pq.top() <= K) {
		if (pq.size() == 1) {
			answer = -1;
			break;
		}
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		sum = first + (second * 2);
		pq.push(sum);
		++answer;
	}
	
	return answer;
}