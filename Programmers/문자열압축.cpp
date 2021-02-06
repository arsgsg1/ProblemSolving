#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
string make_string(int num, string& str)
{
	if (num == 1)
		return str;
	else
		return to_string(num) + str;
}
int solution(string s) {
	int answer = 987654321, len = s.size();
	string comp, str, prev, post;
	int num = 0, idx = 0;
	queue<string> q;
	string make;
	vector<string> result;
	//압축 개수
	for (int c = 1; c <= (len % 2 == 0 ? len / 2 : len / 2 + 1); c++) {
		make.clear();
		idx = 0;
		while (1) {
			if (idx + c > len) {
				str = s.substr(idx);
				if(str.length() != 0)
					q.push(str);
				break;
			}
			q.push(s.substr(idx, c));
			idx += c;
		}
		prev = q.front();
		num = 0;
		while (1) {
			if (q.empty()) {
				make += make_string(num, prev);
				result.push_back(make);
				break;
			}
			post = q.front();
			q.pop();
			if (prev == post)
				++num;
			else {
				make += make_string(num, prev);
				prev = post;
				num = 1;
			}
		}
	}
	for (const auto& item : result)
		answer = min(answer, (int)item.length());
	return answer;
}