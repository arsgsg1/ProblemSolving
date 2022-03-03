#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 4000
int arr[4][MAX_SIZE];
int N;
int main()
{
	int result = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) 
		scanf("%d %d %d %d", &arr[0][i], &arr[1][i], &arr[2][i], &arr[3][i]);
	
	vector<long long> v;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			v.push_back(arr[2][i] + arr[3][j]);
		
	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long temp = arr[0][i] + arr[1][j];
			int low = lower_bound(v.begin(), v.begin() + v.size(), -temp) - v.begin();
			int high = upper_bound(v.begin(), v.begin() + v.size(), -temp) - v.begin();

			if (-temp == v[low])
				//중복 값에 대한 처리
				result += high - low;
		}
	}
	printf("%d\n", result);
	return 0;
}