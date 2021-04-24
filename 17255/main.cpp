#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
string str;
int limit;
unordered_set<string> us;
void dfs(int l, int r, string s, string cur)
{
	if (s.length() == limit) {
		us.insert(s);
		return;
	}
	string temp;
	if (l - 1 >= 0) {
		temp = cur;
		temp.insert(0, 1, str[l - 1]);
		dfs(l - 1, r, s + temp, temp);
	}
	if (r + 1 < str.length()) {
		temp = cur;
		temp += str[r + 1];
		dfs(l, r + 1, s + temp, temp);
	}
}
int main()
{
	cin >> str;
	limit = (str.length() * (str.length() + 1)) / 2;
	for (int i = 0; i < str.length(); i++) {
		string temp = "";
		temp += str[i];
		dfs(i, i, temp, temp);
	}
	printf("%d\n", us.size());
	return 0;
}