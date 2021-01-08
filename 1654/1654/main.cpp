#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int K, N;
bool Possible(const vector<int>& v, long long length)
{
	int sum = 0;
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
void BinSearch(const vector<int>& v)
{
	long long left = 0;
	long long right = pow(2, 31) -1;
	long long mid = (left + right) / 2;
	while (left <= right) {
		if (Possible(v, mid))
			left = mid + 1;
		else
			right = mid - 1;
		mid = (left + right) / 2;
	}
	printf("%lld\n", mid);
}
int main()
{
	scanf("%d %d", &K, &N);
	vector<int> v(K, 0);
	for (int i = 0; i < K; i++) 
		scanf("%d", &v[i]);
	BinSearch(v);
	return 0;
}