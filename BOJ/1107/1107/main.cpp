#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
map<string, set<string>> m;
map<string, set<string>> retake_map;
set<string> product;
int parser(const string& str)
{
	int day = stoi(str.substr(5, 2)) * 30;
	day += stoi(str.substr(8, 2));
	return day;
}
struct Info {
	string pname;
	double ratio;
};
pair<string, string> uname_parser(const string& str)
{
	string uname1 = str.substr(11, 4);
	string uname2 = str.substr(16, 4);
	return { uname1, uname2 };
}
vector<string> solution(vector<string> records, int k, string date) {
	vector<string> answer;
	vector<pair<int, string>> new_record;
	int retake = parser(date);
	int idx = 0;
	for (; idx < records.size(); idx++) {
		int day = parser(records[idx]);
		if (day >= retake - k)
			break;
		auto p = uname_parser(records[idx]);
		m[p.first].insert(p.second);
		product.insert(p.second);
	}
	for (int i = idx; i < records.size(); i++) {
		int day = parser(records[i]);
		if (day >= retake)
			break;
		auto& p = uname_parser(records[i]);
		if (m[p.first].find(p.second) == m[p.first].end()) {
			m[p.first].insert(p.second);
		}
		else {
			retake_map[p.first].insert(p.second);
		}
		product.insert(p.second);
	}
	Info info;
	vector<Info> vInfo;
	for (const auto& p : product) {
		int t1 = 0, t2 = 0;
		for (const auto& re : retake_map) {
			if (re.second.find(p) != re.second.end()) {
				t1++;
			}
		}
		for (const auto& re : m) {
			if (re.second.find(p) != re.second.end()) {
				t2++;
			}
		}
		info.ratio = (double)t1 / t2 * 100;
		info.pname = p;
		vInfo.push_back(info);
	}
	return answer;
}

void main()
{
	solution({ "2020-02-02 uid1 pid1", "2020-02-26 uid1 pid1", "2020-02-26 uid2 pid1", "2020-02-27 uid3 pid2", "2020-02-28 uid4 pid2", "2020-02-29 uid3 pid3", "2020-03-01 uid4 pid3", "2020-03-03 uid1 pid1", "2020-03-04 uid2 pid1", "2020-03-05 uid3 pid2", "2020-03-05 uid3 pid3", "2020-03-05 uid3 pid3", "2020-03-06 uid1 pid4" },
		10, "2020-03-05");
	solution({ "2020-02-02 uid141 pid141", "2020-02-03 uid141 pid32", "2020-02-04 uid32 pid32", "2020-02-05 uid32 pid141" },
		10, "2020-02-05");
	solution({ "2020-01-01 uid1000 pid5000" }, 10, "2020-01-11");
}