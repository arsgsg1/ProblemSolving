#include <iostream>
using namespace std;
int A, B, C;
int arr[1000000];
int main()
{
	scanf("%d", &A);
	for (int i = 0; i < A; i++)
		scanf("%d", &arr[i]);
	scanf("%d %d", &B, &C);
	long long cnt = 0;
	for (int i = 0; i < A; i++) {
		++cnt;
		arr[i] -= B;
	}
	for (int i = 0; i < A; i++) {
		if (arr[i] % C > 0)
			++cnt;
		if(arr[i] > 0)
			cnt += arr[i] / C;
	}
	printf("%lld\n", cnt);
	return 0;
}