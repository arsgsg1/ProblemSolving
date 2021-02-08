#include <string>
#include <vector>
#include <map>

using namespace std;
map<string, vector<string>> m;
int solution(vector<vector<string>> clothes) {
	int answer = 0;
	string type, wear;
	vector<string> keys;
	for (int i = 0; i<clothes.size(); i++) {
		wear = clothes[i][0];
		type = clothes[i][1];
		if (m.find(type) == m.end()) {
			m.insert(make_pair(type, vector<string>()));
			m[type].push_back(wear);
			m[type].push_back("No");
			keys.push_back(type);
		}
		else
			m[type].push_back(wear);
	}

	//각각을 조합하는 경우의 수
	int sum = keys.size() == 1 ? m[keys[0]].size() : m[keys[0]].size();
	for (int i = 1; i<keys.size(); i++)
		sum = sum * (m[keys[i]].size());
	answer += sum;
	answer -= 1;
	return answer;
}