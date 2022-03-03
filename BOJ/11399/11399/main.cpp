#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int GetWaitingTime(vector<int>& v)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			sum += v[j];
		}
		sum += v[i];
	}
	return sum;
}
int main()
{
	cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	printf("%d\n", GetWaitingTime(v));
	return 0;
}