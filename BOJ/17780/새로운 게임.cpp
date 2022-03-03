//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <deque>
#include <stack>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
* Complete the 'segment' function below.
*
* The function is expected to return an INTEGER.
* The function accepts following parameters:
*  1. INTEGER x
*  2. INTEGER_ARRAY space
*/

int segment(int x, vector<int> space) {
	int chunkNum = 1;
	stack<int> s;
	s.push(0);
	int len = space.size();
	for (int i = 1; i < len; i++) {
		if (i < x) {
			if (space[i] < space[s.top()]) {
				s.pop();
				s.push(i);
			}
		}
		else {
			int peek = s.top();
			if (peek >= chunkNum) {
				s.push(space[i] < space[peek] ? i : peek);
			}
			else {
				s.push(i);

				int j = chunkNum;
				int cnt = 0;
				while (cnt++ < x) {
					if (space[j] < space[s.top()]) {
						s.pop();
						s.push(j);
					}
					j++;
				}
			}
			chunkNum++;
		}
	}
	int answer = 0;
	while (!s.empty()) {
		answer = max(answer, space[s.top()]);
		s.pop();
	}
	return answer;
}
int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string x_temp;
	getline(cin, x_temp);

	int x = stoi(ltrim(rtrim(x_temp)));

	string space_count_temp;
	getline(cin, space_count_temp);

	int space_count = stoi(ltrim(rtrim(space_count_temp)));

	vector<int> space(space_count);

	for (int i = 0; i < space_count; i++) {
		string space_item_temp;
		getline(cin, space_item_temp);

		int space_item = stoi(ltrim(rtrim(space_item_temp)));

		space[i] = space_item;
	}

	int result = segment(x, space);

	fout << result << "\n";

	fout.close();

	return 0;
}

string ltrim(const string &str) {
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
	);

	return s;
}

string rtrim(const string &str) {
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end()
	);

	return s;
}
