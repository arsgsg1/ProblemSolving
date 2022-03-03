#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
bool BinSearch(const vector<int>& v, int target)
{
	int left = 0;
	int right = v.size() - 1;
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (v[mid] == target) {
			return true;
		}
		else if (v[mid] < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return false;
}
int main()
{
	scanf("%d", &N);
	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &v[i]);
	sort(v.begin(), v.end());

	scanf("%d", &M);
	int temp;
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		if (BinSearch(v, temp))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}