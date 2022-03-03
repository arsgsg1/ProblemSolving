#include <iostream>
#include <set>
#include <string>
using namespace std;
int N;
int main()
{
	cin >> N;
	int answer = N;
	string str;
	for (int t = 0; t < N; t++) {
		cin >> str;
		set<char> s;
		char before = 0;
		for (int i = 0; i < str.length(); i++) {
			if (before == str[i])
				continue;
			if (s.find(str[i]) == s.end())
				s.insert(str[i]);
			else {
				answer--;
				break;
			}
			before = str[i];
		}
	}
	printf("%d\n", answer);
	return 0;
}