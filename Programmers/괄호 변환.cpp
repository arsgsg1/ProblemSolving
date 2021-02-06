#include <string>
#include <vector>
#include <stack>

using namespace std;
bool IsUnvalance(const string& str)
{
	int l = 0, r = 0;
	for (const auto& ch : str) {
		if (ch == '(')
			l++;
		else if (ch == ')')
			r++;
	}
	if (l != r)
		return true;
	else
		return false;
}
bool IsRight(const string& str)
{
	stack<char> s;
	for (const auto& ch : str) {
		if (ch == '(')
			s.push(ch);
		else if (!s.empty()) {
			if (s.top() == '(')
				s.pop();
			else
				s.push(ch);
		}
	}
	if (s.empty())
		return true;
	else
		return false;
}
string recur(string str)
{
	if (str.size() == 0)
		return "";
	if (IsRight(str))
		return str;
	string u, v, result;
	int len = str.length(), idx;
	for (idx = 2; idx <= len; idx += 2) {
		u = str.substr(0, idx);
		if (!IsUnvalance(u))
			break;
	}
	v = str.substr(idx);
	if (IsRight(u)) {
		result = u + recur(v);
	}
	else {
		result.push_back('(');
		result += recur(v);
		result.push_back(')');
		u.erase(0, 1);
		u.pop_back();
		for (const auto& ch : u) {
			if (ch == '(')
				result += ')';
			else
				result += '(';
		}
	}
	return result;
}
string solution(string p) {
	string answer = "";
	if (p.length() == 0)
		return answer;
	answer = recur(p);
	return answer;
}