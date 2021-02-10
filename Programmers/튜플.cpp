#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;
typedef struct Node {
	int cnt;
	string str;
};
bool cmp(const Node& n1, const Node& n2)
{
	return n1.cnt < n2.cnt;
}
vector<int> solution(string s) {
	vector<int> answer;
	vector<Node> v;
	int len = s.length();
	int cnt = 0;
	string str;
	Node n;
	bool start = false;
	//¹®ÀÚ¿­ ÆÄ½Ì
	for (int i = 1; i < len - 1; i++) {
		if (s[i] == '{') {
			start = true;
		}
		else if (s[i] == '}') {
			start = false;
			n.cnt = cnt;
			n.str = str;
			cnt = 0;
			str.clear();
			v.push_back(n);
		}
		else if (start == true && s[i] == ',') {
			cnt++;
			str += s[i];
		}
		else if (start == true && s[i] <= '9' && s[i] >= '0') {
			str += s[i];
		}
	}
	sort(v.begin(), v.end(), cmp);
	set<int> items;
	for (const auto& n : v) {
		istringstream ss(n.str);
		int num = 0;
		while (getline(ss, str, ',')) {
			num = atoi(str.c_str());
			if (items.find(num) == items.end()) {
				items.insert(num);
				answer.push_back(num);
			}
		}
	}
	return answer;
}