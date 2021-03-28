#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
/*
접근
1. 가장 작은 길이의 문자열이 다른 문자열들의 접두어가 아니라면,
접두사 X가 될 수 있음
2. 접두어가 되는 문자열이 하나라도 있으면, 접두사 X가 될 수 없음
*/
struct Node {
	string str;
	int len;
};
bool cmp(Node& n1, Node& n2)
{
	return n1.len < n2.len;
}
int main()
{
	cin >> N;
	Node n;
	vector<Node> v;
	for (int i = 0; i < N; i++) {
		cin >> n.str;
		n.len = n.str.length();
		v.push_back(n);
	}
	sort(v.begin(), v.end(), cmp);
	int answer = N;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[j].str.find(v[i].str) == 0) {
				answer--;
				break;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}