#include <iostream>
using namespace std;
#define MAX_SIZE 100000
int N;
int arr[MAX_SIZE];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	int start = 0, end = N - 1;
	long long sum = arr[start] + arr[end];
	long long minimum = abs(sum) + 1;
	int idx1, idx2;
	while (start < end) {
		sum = arr[start] + arr[end];
		if (abs(sum) < minimum) {
			minimum = abs(sum);
			idx1 = start;
			idx2 = end;
		}
		if (sum < 0)
			start++;
		else
			end--;
	}
	printf("%d %d\n", arr[idx1], arr[idx2]);
	return 0;
}