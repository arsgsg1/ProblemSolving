#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	map<int, int> m;
	int limit = nums.size() / 2;
	for (const auto& num : nums)
		m[num]++;
	int kind = 0;
	for (const auto& it : m) {
		if (answer == limit)
			break;
		if (it.first != kind) {
			answer++;
			kind = it.first;
		}
	}
	return answer;
}