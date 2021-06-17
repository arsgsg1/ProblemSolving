#include <iostream>
#include <vector>
using namespace std;
int N;
bool visit[9];
vector<int> picked;
void print()
{
	for (const auto& pick : picked) {
		printf("%d ", pick);
	}
	printf("\n");
}
void dfs(int n)
{
	if (picked.size() == N) {
		print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			picked.push_back(i);
			dfs(i);
			visit[i] = false;
			picked.pop_back();
		}
	}
}
int main()
{
	cin >> N;
	dfs(1);
	return 0;
}