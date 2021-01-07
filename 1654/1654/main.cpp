#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long long K, N, Max = 0;
bool Possible(const vector<long long>& v, long long length)
{
	long long sum = 0;
	for (const auto& s : v) {
		if (length > s)
			continue;
		else
			sum += s / length;
	}
	if (sum >= N)
		return true;
	else
		return false;
}
void BinSearch(vector<long long>& v)
{
	long long left = 1;
	long long right = Max;
	long long mid = (left + right) / 2;
	while (left <= right) {
		if (Possible(v, mid))
			left = mid + 1;
		else
			right = mid - 1;
		mid = (left + right) / 2;
	}
	printf("%lld\n", right);
}
int main()
{
	scanf("%lld %lld", &K, &N);
	vector<long long> v(K, 0);
	for (int i = 0; i < K; i++) {
		scanf("%lld", &v[i]);
		if (Max < v[i])
			Max = v[i];
	}
	BinSearch(v);
	return 0;
}