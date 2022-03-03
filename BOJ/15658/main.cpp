//next_permutation : O(n!)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> number;
vector<int> op;
int MinValue = 1e9 + 1, MaxValue = -1e9 - 1;
void dfs(int idx, int plus, int minus, int mul, int div, int sum)
{
	if (idx == N) {
		MinValue = min(sum, MinValue);
		MaxValue = max(sum, MaxValue);
		return;
	}
	if(plus != 0)
		dfs(idx + 1, plus - 1, minus, mul, div, sum + number[idx]);
	if(minus != 0)
		dfs(idx + 1, plus, minus - 1, mul, div, sum - number[idx]);
	if(mul != 0)
		dfs(idx + 1, plus, minus, mul - 1, div, sum * number[idx]);
	if(div != 0)
		dfs(idx + 1, plus, minus, mul, div - 1, sum / number[idx]);
}
int main()
{
	int temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		number.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> temp;
		op.push_back(temp);
	}
	dfs(1, op[0], op[1], op[2], op[3], number[0]);
	printf("%d\n%d\n", MaxValue, MinValue);
	return 0;
}