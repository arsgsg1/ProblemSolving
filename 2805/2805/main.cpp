#include <iostream>
#include <vector>
using namespace std;
int N, M;

bool possible(vector<int>& v, int height)
{
	long sum = 0;
	for (const auto& s : v) {
		if (height >= s)
			continue;
		else
			sum += s - height;
	}
	if (sum >= M)
		return true;
	else
		return false;
}
void BinSearch(vector<int>& v)
{
	int left = 0;
	int right = 2000000000;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (possible(v, mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	printf("%d\n", right);
}
int main()
{
	scanf("%d %d", &N, &M);
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	BinSearch(v);
	return 0;
}