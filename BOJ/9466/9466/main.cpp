#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 100001

int testcase, cnt;
int arr[MAX];
bool visit[MAX], check[MAX];

void DFS(int index) {
	int next_num = arr[index];
	visit[index] = true;

	if (!visit[next_num])
		DFS(next_num);
	else {
		if (!check[next_num]) {
			for (int i = next_num; i != index; i = arr[i]) cnt++;
			cnt++;
		}
	}
	check[index] = true;
}

void Memset_Arr() {
	memset(arr, 0, sizeof(arr));
	memset(visit, false, sizeof(visit));
	memset(check, false, sizeof(check));
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}

int main() {
	init();
	cin >> testcase;

	while (testcase--) {
		Memset_Arr();
		int N; cin >> N;

		for (int i = 1; i <= N; i++) cin >> arr[i];
		cnt = 0;
		for (int i = 1; i <= N; i++)
			if (!visit[i])
				DFS(i);
		cout << N - cnt << endl;
	}
	return 0;
}