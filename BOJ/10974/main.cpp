#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> comb;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		comb.push_back(i);
	do {
		for (const auto& i : comb)
			printf("%d ", i);
		printf("\n");
	} while (next_permutation(comb.begin(), comb.end()));
	return 0;
}