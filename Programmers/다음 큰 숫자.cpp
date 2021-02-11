#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
#define MAX_SIZE 1000000
int GetNumofOne(int num)
{
	string s;
	int temp = 1, cnt = 0;
	while (num >= 0) {
		if (temp * 2 > num) {
			break;
		}
		temp *= 2;
	}
	while (1) {
		if (temp == 0)
			break;
		if (num - temp < 0) {
			s.push_back('0');
		}
		else {
			s.push_back('1');
			num -= temp;
			cnt++;
		}
		temp /= 2;
	}
	return cnt;
}
int solution(int n) {
	int answer = 0;
	int cnt = GetNumofOne(n);
	for (int i = n + 1; i<MAX_SIZE; i++) {
		if (cnt == GetNumofOne(i)) {
			return i;
		}
	}
	return answer;
}