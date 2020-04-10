#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_VAL 1000000

bool IsPossible(int digits[], int val)
{
	
	int digit = 0;
	do
	{
		//못쓰는 버튼이라면
		if (digits[val % 10])
			return false;
		val /= 10;
	} while (val != 0);
	return true;
}

int GetDigits(int val)
{
	if (val == 0) return 1;
	int cnt = 0;
	while (val)
	{
		cnt++;
		val /= 10;
	}
	return cnt;
}

int Solution(vector<int>& btns, int channel)
{
	if (channel == 100) return 0;
	int digits[10] = { 0,}, mostNearNum = 1000007, result = 1000007, dist = 0, temp;
	for (const auto& btn : btns)
		digits[btn] = 1;
	mostNearNum = abs(channel - 100);
	temp = mostNearNum;
	//모든 경우의 수 찾기
	for (int i = 0; i < MAX_VAL; i++) {
		if (IsPossible(digits, i)) {
			//가장 가까운 수 찾기 -> 차이 비교 (수직선 개념)
			mostNearNum = abs(channel - i);
			//가까운 수와 목표 수와의 거리 비교 (수직선 개념)
			dist = abs(channel - mostNearNum);
			//버튼 누른 횟수의 최솟값 = 가장 가까운수의 자릿수 + 거리 비교 값(+, - 버튼을 누른 횟수)
			result = min(result, mostNearNum + GetDigits(dist));
			
		}
	}
	result = min(temp, result);
	return result;
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
	printf("%d", Solution(btns, channel));
	return 0;
}