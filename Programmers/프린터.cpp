#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	priority_queue<int> pq;
	queue<int> q;
	for (int i = 0; i < priorities.size(); i++) {
		pq.push(priorities[i]);
		q.push(i);
	}
	while (!q.empty()) {
		int l = q.front();
		if (priorities[l] == pq.top()) {
			q.pop();
			pq.pop();
			answer++;
			if (l == location)
				break;
		}
		else {
			q.pop();
			q.push(l);
		}
	}
	return answer;
}