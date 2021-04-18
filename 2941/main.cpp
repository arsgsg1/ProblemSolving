#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	string str;
	cin >> str;
	vector<string> v;
	v = { "c=" , "c-" , "dz=", "d-", 
		"lj", "nj", "s=", "z=" };
	string temp;
	int answer = 0;
	for (int i = 0; i < str.length(); i++) {
		temp += str[i];
		for (int j = 0; j < v.size(); j++) {
			const string &pattern = v[j];
			if (temp.find(pattern) != string::npos) {
				for (int s = 0; s < pattern.length(); s++)
					temp.pop_back();
				answer++;
				answer += temp.length();
				temp.clear();
			}
		}
	}
	answer += temp.length();
	printf("%d\n", answer);
	return 0;
}