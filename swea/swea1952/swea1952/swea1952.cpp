//수영장
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int day, mon, tmon, year;
int p[13];
int dm[13];
int low[13];

int min(int x, int y) {
	return (x < y) ? x : y;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> day >> mon >> tmon >> year;
		for (int i = 1; i <= 12; i++)
			cin >> p[i];
		for (int i = 1; i <= 12; i++)
			dm[i] = min(p[i] * day, mon);
		for (int i = 1; i <= 12; i++) {
			low[i] = low[i - 1] + dm[i];
			if (i - 3 >= 0)
				low[i] = min(low[i], low[i - 3] + tmon);
		}
		if (low[12] > year)
			low[12] = year;
		cout << "#" << test_case << ' ' << low[12] << '\n';
	}
	return 0;
}