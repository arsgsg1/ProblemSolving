#include <iostream>
#include <algorithm>
typedef long long ll;
#define endl '\n'
using namespace std;
const int sz = 1e4;
int arr[sz], n, temp, idx, idx2;
ll cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i<n; ++i)cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i<n - 2; ++i) {
		for (int j = i + 1; j<n - 1; ++j) {
			temp = (-1)*(arr[i] + arr[j]);
			idx = lower_bound(arr + j + 1, arr + n, temp) - arr;
			idx2 = upper_bound(arr + j + 1, arr + n, temp) - arr;
			cnt += idx2 - idx;
		}
	}
	cout << cnt << endl;
	return 0;
}