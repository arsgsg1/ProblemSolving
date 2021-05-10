#include <iostream>
#include <string>
#include <map>
using namespace std;
int Count = 0;
map<string, int> m;
int main()
{
	string s;
	while (getline(cin, s)) {
		m[s]++;
		Count++;
	}
	double answer;
	for (map<string, int>::iterator it = m.begin();
		it != m.end(); it++) {
		answer = (it->second / (double)Count) * 100;
		printf("%s %.4lf\n", it->first.c_str(), answer);
	}
	return 0;
}