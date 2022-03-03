#include <iostream>
#include <stack>
#include <string>
using namespace std;
#define T s.top()
int main()
{
	string str;
	cin >> str;
	stack<char> s;
	
	for (const auto& c : str) {
		
		if (c >= 'A' && c <= 'Z') {
			cout << c;
		}
		else {
			if (c == '(') {
				s.push(c);
			}
			else if(c == '*' || c == '/') {
				while (!s.empty() && (T == '*' || T == '/')) {
					cout << T;
					s.pop();
				}
				s.push(c);
			}
			else if(c == '+' || c == '-'){
				while (!s.empty() && T != '(') {
					cout << T;
					s.pop();
				}
				s.push(c);
			}
			else if (c == ')') {
				while (!s.empty() && T != '(') {
					cout << T;
					s.pop();
				}
				s.pop();
			}
		}	
	}
	while (!s.empty()) {
		cout << T;
		s.pop();
	}
	return 0;
}