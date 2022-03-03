#include <iostream>
using namespace std;
int N, M;
int arr[100001];
long long cul[100001];
int main()
{
	cin >> N >> M;
	scanf("%d", &arr[0]);
	cul[0] = arr[0];
	for (int i = 1; i < N; i++) {
		scanf("%d", &arr[i]);
		cul[i] = cul[i - 1] + arr[i];
	}
	int s, e;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &s, &e);
		s--;
		e--;
		printf("%lld\n", cul[e] - cul[s] + arr[s]);
	}
	return 0;
}