

#include "pch.h"
#include <iostream>
#include <algorithm>
#define MAX_LEN 10001
int arr[MAX_LEN];
int d[MAX_LEN];
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		int Max = -1, Min = MAX_LEN;
		for (int j = i; j > 0; j--) {
			Max = max(Max, arr[j]);
			Min = min(Min, arr[j]);
			d[i] = max(d[i], Max - Min + d[j - 1]);
		}
	}
	printf("%d\n", d[n]);
	return 0;
}
