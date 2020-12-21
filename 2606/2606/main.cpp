#include <string>
#include <vector>
#include <queue>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N, M, a, b;
int num = 0;
vector<pair<int, int> > v[101];
bool visited[101];

void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		if (visited[v[x][i].first] == false) {
			visited[v[x][i].first] = true;
			num++;
			dfs(v[x][i].first);
		}
	}
}

int main(void) {
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(make_pair(b, b));
		v[b].push_back(make_pair(a, a));
	}
	visited[1] = true;
	dfs(1);
	cout << num;
}