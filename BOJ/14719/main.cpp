#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int H, W;
vector<int> arr;
int main()
{
	cin >> H >> W;
	arr = vector<int>(W);
	for (int i = 0; i < W; i++)
		cin >> arr[i];
	vector<int>::iterator it;
	int answer = 0;
	for (int i = 1; i < W - 1; i++) {
		int left = 0, right = 0;
		it = arr.begin() + i;
		left = *max_element(arr.begin(), it);
		right = *max_element(it, arr.end());
		answer += max(0, min(left, right) - *it);
	}
	printf("%d\n", answer);
	return 0;
}