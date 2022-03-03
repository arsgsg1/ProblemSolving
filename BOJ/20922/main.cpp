#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<int, int> um;
int N, K;
int main()
{
	cin >> N >> K;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	int s = 0, e = 0;
	int answer = 0, len = 0;
	while (e < N) {
		int num = v[e];
		um[num]++;
		if (um[num] > K) {
			um[num]--;
			um[v[s]]--;
			s++;
		}
		else {
			e++;
			len = e - s;
			answer = max(len, answer);
		}
	}
	printf("%d\n", answer);
	return 0;
}