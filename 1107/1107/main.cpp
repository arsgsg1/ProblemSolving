#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define MAX_VAL 1000000

bool IsPossible(int digits[], int val)
{
	int digit = 0;
	while (val != 0)
	{
		//못쓰는 버튼이라면
		if (digits[val % 10])
			return false;
		val /= 10;
	}
	return true;
}

int Solution(vector<int>& btns, int channel)
{
	int digits[10] = { 0,};
	for (const auto& btn : btns)
		digits[btn] = 1;

	//모든 경우의 수 찾기
	for (int i = 0; i < MAX_VAL; i++) {
		if (IsPossible(digits, i)) {

		}
	}
	return 0;
}
int main()
{
	int n, btn, channel;
	vector<int> btns;
	cin >> channel;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> btn;
		btns.push_back(btn);
	}
	Solution(btns, channel);
	return 0;
}