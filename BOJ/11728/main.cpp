#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> v(N, 0);
	vector<int> w(M, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < M; i++)
		scanf("%d", &w[i]);
	vector<int> result;
	int n = 0, m = 0;
	int size_v = v.size(), size_w = w.size();
	while (n < size_v && m < size_w) {
		if (v[n] < w[m]) {
			result.push_back(v[n]);
			n++;
		}
		else {
			result.push_back(w[m]);
			m++;
		}
	}
	for (int i = n; i < size_v; i++)
		result.push_back(v[i]);
	for (int i = m; i < size_w; i++)
		result.push_back(w[i]);
	for (const auto& item : result)
		printf("%d ", item);
	return 0;
}