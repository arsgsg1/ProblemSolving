#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v(9, 0);
bool visit[9];
bool check(vector<int>& picked)
{
	int sum = 0;
	for (const auto& pick : picked)
		sum += pick;
	if (sum == 100)
		return true;
	else
		return false;
}
void dfs(int n, vector<int>& picked, int toPick)
{
	if (toPick == 0) {
		if (check(picked)) {
			for (const auto& pick : picked) {
				printf("%d\n", pick);
			}
			exit(0);
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			picked.push_back(v[i]);
			dfs(n, picked, toPick - 1);
			visit[i] = false;
			picked.pop_back();
		}
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
		scanf("%d", &v[i]);
	vector<int> picked;
	dfs(9, picked, 7);
	return 0;
}