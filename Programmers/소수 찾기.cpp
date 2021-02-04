#include <string>
#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

unordered_set <int> s;
string str = "";
bool check[7];

void find_all_numbers(int depth, int limit, string& numbers) {
	if (depth == limit) return;

	for (int i = 0; i < limit; i++) {
		if (!check[i]) {
			check[i] = true;
			str.push_back(numbers[i]);
			s.insert(stoi(str));
			find_all_numbers(depth + 1, limit, numbers);
			str.pop_back();
			check[i] = false;
		}
	}
}
bool IsPrime(int num)
{
	if (num < 2)
		return false;
	int s = sqrt(num);
	for (int i = 2; i <= s; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}
int solution(string numbers) {
	int size = numbers.size();

	find_all_numbers(0, size, numbers);

	int answer = 0;

	for (const auto& it : s) {
		if (IsPrime(it)) {
			answer++;
		}
	}

	return answer;
}