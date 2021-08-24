#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const char moum[] = { 'a', 'e', 'i', 'o', 'u' };
int L, C;
bool visit[15];
bool canPassword(const string& str)
{
	int m_cnt = 0, g_cnt = 0;
	for (const auto& c : str) {
		for (int i = 0; i < 5; i++) {
			if (moum[i] == c)
				m_cnt++;
		}
	}

	g_cnt = str.size() - m_cnt;
	return m_cnt >= 1 && g_cnt >= 2;
}

void backtrack(const vector<char>& v, string& picked, int idx)
{
	if (picked.size() == L) {
		if (canPassword(picked)) {
			cout << picked << endl;
		}
	}
	for (int i = idx; i < C; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			picked.push_back(v[i]);
			backtrack(v, picked, i + 1);
			visit[i] = false;
			picked.pop_back();
		}
	}
}

int main()
{
	vector<char> alpha;
	string picked;
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		char ch;
		cin >> ch;
		alpha.push_back(ch);
	}
	sort(alpha.begin(), alpha.end());
	backtrack(alpha, picked, 0);
	return 0;
}