#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	//모든 트럭이 다리를 건너는 최소 시간
	int answer = 1;
	int limit = 0;
	//트럭의 무게 제한, 시간을 저장
	queue<pair<int, int>> wait, bridge;
	for (int i = 0; i < truck_weights.size(); i++)
		wait.push({ truck_weights[i], 0 });
	int w, t;
	//대기 중인 트럭이나 다리를 통과하는 트럭이 없을 때까지
	while (!wait.empty() || !bridge.empty()) {
		answer++;
		if (!wait.empty()) {
			w = wait.front().first;
			t = wait.front().second;
			if (limit + w <= weight) {
				wait.pop();
				limit += w;
				bridge.push({ w, t });
			}
		}
		int len = bridge.size();
		for (int i = 0; i < len; i++) {
			w = bridge.front().first;
			t = bridge.front().second;
			bridge.pop();
			if (t + 1 < bridge_length)
				bridge.push({ w, t + 1 });
			//다리에서 트럭 통과
			else
				limit -= w;
		}
	}
	return answer;
}