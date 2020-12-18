#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define BIT_MASK 0x7fffffff
int N, M;
int substi(const string& str)
{
	int num = 0;
	for (const auto& item : str) {
		num |= BIT_MASK & (1 << item - 'a');
	}
	return num;
}
void oper(int idx, char c, vector<int>& v, const vector<int>& org)
{
	int len = v.size();
	for (int i = 0; i < len; i++) {
		if (idx == 1) {
			v[i] = v[i] & ~(1 << c - 'a');
		}
		else {
			v[i] |= org[i] & (1 << c - 'a');
		}
	}
}
int main()
{
	string s;
	cin >> N >> M;
	vector<int> v(N, 0);
	vector<int> org(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> s;
		v[i] = substi(s);
	}
	org = v;
	int op, cnt = 0;
	char c;
	for (int i = 0; i < M; i++) {
		cin >> op >> c;
		oper(op, c, v, org);
		for (int j = 0; j < org.size(); j++) {
			if (v[j] == org[j]) {
				++cnt;
			}
		}
		printf("%d\n", cnt);
		cnt = 0;
	}
	return 0;
}