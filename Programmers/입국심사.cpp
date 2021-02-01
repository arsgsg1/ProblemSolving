#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool IsPossible(vector<int>& times, long long limit, long long n)
{
	long long sum = 0;
	for (const auto& time : times)
		sum += limit / time;
	
	if (sum >= n)
		return true;
	else
		return false;
}
long long solution(int n, vector<int> times)
{
	//모든 사람들이 심사를 받는데 걸리는 최소 시간
	long long answer = 0;
	long long Max = *max_element(times.begin(), times.end());
	long long left = 0, right = Max * n;
	long long mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;

		if (IsPossible(times, mid, n))
			right = mid - 1;
		else
			left = mid + 1;
	}
	answer = left;
	return answer;
}
int main()
{
	int n, t;
	scanf("%d %d", &n, &t);
	vector<int> times(t, 0);
	for (int i = 0; i < t; i++)
		scanf("%d", &times[i]);
	printf("%lld\n", solution(n, times));
	return 0;
}