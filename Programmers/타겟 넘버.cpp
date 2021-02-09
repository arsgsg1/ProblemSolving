#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define MAX_SIZE 1000
int target_number = 0;
int result = 0;
void dfs(vector<int>& v, int idx, int sum)
{
	if (idx == v.size()) {
		if (sum == target_number)
			result++;
		return;
	}
	int next = sum + v[idx];
	dfs(v, idx + 1, next);
	next = sum - v[idx];
	dfs(v, idx + 1, next);
}
int solution(vector<int> numbers, int target) {
	int answer = 0;
	target_number = target;
	dfs(numbers, 0, 0);
	answer = result;
	return answer;
}