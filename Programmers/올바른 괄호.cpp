#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack<char> st;
	for (const auto& c : s) {
		if (c == '(')
			st.push(c);
		else if (!st.empty())
			st.pop();
		else
			st.push(c);
	}
	if (st.empty())
		answer = true;
	else
		answer = false;
	return answer;
}