#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int L, C;
vector<char> charset;
vector<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
bool IsPassword(vector<char>& picked)
{
	/*
	암호를 판단하는 기준
	모음의 개수 >= 1
	조합의 길이 - 모음의 개수 >= 2
	*/
	int cnt = 0;
	for (const auto& ch1 : picked) {
		for (const auto& ch2 : vowels) {
			if (ch1 == ch2) {
				++cnt;
				break;
			}
		}
	}
	if (cnt >= 1) {
		if (picked.size() - cnt >= 2) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
void printPicked(vector<char>& picked)
{
	for (const auto& item : picked) {
		printf("%c", item);
	}
	printf("\n");
}
void pick(int n, vector<char>& picked, int toPick, int idx)
{
	if (toPick == 0 && IsPassword(picked)){	printPicked(picked); return; }
	int smallest = picked.empty() ? 0 : idx + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(charset[next]);
		pick(n, picked, toPick - 1, next);
		picked.pop_back();
	}
}
int main()
{
	vector<char> picked;
	cin >> L >> C;
	char ch;
	for (int i = 0; i < C; i++) {
		cin >> ch;
		charset.push_back(ch);
	}
	sort(charset.begin(), charset.end());
	pick(C, picked, L, 0);
	return 0;
}