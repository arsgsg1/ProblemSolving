#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
string D(const string& str)
{
	int value = atoi(str.c_str());
	if (value * 2 > 9999) {
		value = (value * 2) % 10000;
	}
	else {
		value *= 2;
	}
	char ch[10];
	sprintf_s(ch, "%04d", value);
	return ch;
}

string S(const string& str)
{
	int value = atoi(str.c_str());
	if (value == 0) {
		value = 9999;
	}
	else {
		value --;
	}
	char ch[10];
	sprintf_s(ch, "%04d", value);
	return ch;
}

string L(const string& str)
{
	string temp = str;
	char ch = temp.at(0);
	temp.erase(0, 1);
	temp += ch;
	return temp;
}

string R(const string& str)
{
	string temp = str;
	char ch = temp.at(3);
	temp.erase(3);
	temp = ch + temp;
	return temp;
}

const char* Solution(const string& start, const string& goal)
{
	queue<pair<string, string>> q;
	string temp = "", value;
	string d, s, l, r;
	bool bField[10003] = { false };
	int istart = atoi(start.c_str()), igoal = atoi(goal.c_str());
	int id, is, il, ir;
	q.push(make_pair(start, temp));
	bField[istart] = true;
	while (!q.empty())
	{
		value = q.front().first;
		temp = q.front().second;
		if (atoi(value.c_str()) == igoal) {
			printf("%s\n", temp.c_str());
			break;
		}
		q.pop();
		d = D(value); id = atoi(d.c_str());
		s = S(value); is = atoi(s.c_str());
		l = L(value); il = atoi(l.c_str());
		r = R(value); ir = atoi(r.c_str());
		
		if (!bField[id]) {
			bField[id] = true;
			q.push(make_pair(d, temp + "D"));
		}if (!bField[is]) {
			bField[is] = true;
			q.push(make_pair(s, temp + "S"));
		}if (!bField[il]) {
			bField[il] = true;
			q.push(make_pair(l, temp + "L"));
		}if (!bField[ir]) {
			bField[ir] = true;
			q.push(make_pair(r, temp + "R"));
		}
	}
	
	return "";
}

int main()
{
	int TestCase;
	int IntStart, IntGoal;
	char start[100] = { 0 }, goal[100] = { 0 };
	cin >> TestCase;
	for (int i = 0; i < TestCase; i++) {
		cin >> IntStart >> IntGoal;
		sprintf_s(start, "%04d", IntStart);
		sprintf_s(goal, "%04d", IntGoal);
		Solution(start, goal);
	}
	return 0;
}
