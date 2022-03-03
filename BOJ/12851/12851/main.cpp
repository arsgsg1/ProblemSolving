#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100001
int field[MAX_SIZE] = { 0, };
int N, K, goal = 987654321;
int nextPos(int pos, int i)
{
	switch (i)
	{
	case 0:
		return pos + 1;
	case 1:
		return pos - 1;
	case 2:
		return pos * 2;
	}
}
int main()
{
	cin >> N >> K;
	if (N == K) {
		printf("%d\n%d\n", 0, 1);
		return 0;
	}
	field[N] = 1;
	queue<int> q;
	vector<int> v;
	q.push(N);
	
	while (!q.empty()) {
		int cur = q.front();
		int next = 0;
		q.pop();
		if (goal < field[cur]) {
			continue;
		}
		for (int i = 0; i < 3; i++) {
			next = nextPos(cur, i);
			if (next == K) {
				goal = field[cur];
				v.push_back(field[cur]);
			}
			if (next < 0 || next > MAX_SIZE) { continue; }
			if (field[next] == 0 || (field[next] >= field[cur] + 1)) {
				field[next] = field[cur] + 1;
				q.push(next);
			}
		}
	}
	sort(v.begin(), v.end());
	int result = v[0] , cnt = 0;
	for (const auto& item : v) {
		if (result == item) 
			++cnt;
		else 
			break;
	}
	printf("%d\n%d\n", result, cnt);
	return 0;
}