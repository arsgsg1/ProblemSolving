#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N;
int main()
{
	cin >> N;
	vector<int> v(N, 0);
	int answer = 0, sum = 0;
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	do {
		sum = 0;
		for (int i = 0; i < N - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		answer = max(answer, sum);
	} while (next_permutation(v.begin(), v.end()));
	cout << answer << endl;
	return 0;
}