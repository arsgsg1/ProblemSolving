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
		//������ ��ư�̶��
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
	//��� ����� �� ã��
	for (int i = 0; i < MAX_VAL; i++) {
		if (IsPossible(digits, i)) {
			//���� ����� �� ã�� -> ���� �� (������ ����)
			mostNearNum = abs(channel - i);
			//����� ���� ��ǥ ������ �Ÿ� �� (������ ����)
			dist = abs(channel - mostNearNum);
			//��ư ���� Ƚ���� �ּڰ� = ���� �������� �ڸ��� + �Ÿ� �� ��(+, - ��ư�� ���� Ƚ��)
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