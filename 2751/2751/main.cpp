#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main()
{
	cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (const auto& item : v) {
		printf("%d\n", item);
	}
	return 0;
}