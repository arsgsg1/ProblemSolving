#include <iostream>
#include <queue>
#include <stack>
using namespace std;
#define MAX_LEN 10002
int itrack[MAX_LEN] = { 0, };
char ctrack[MAX_LEN] = { 0, };
queue<int> q;
stack<int> s;

inline int D(int num)
{
	int value;
	if (num * 2 > 9999) {
		value = (num * 2) % 10000;
	}
	else {
		value = num * 2;
	}
	return value;
}

inline int S(int num)
{
	int value;
	if (num == 0) {
		value = 9999;
	}
	else {
		value = num - 1;
	}
	return value;
}

inline int L(int num)
{
	int value, digit;
	digit = num / 1000;
	value = num % 1000 * 10 + digit;
	return value;
}

inline int R(int num)
{
	int value, digit;
	digit = num % 10;
	value = num / 10 + digit * 1000;
	return value;
}

void Print(int idx, int start, int itrack[], char ctrack[])
{
	while (1)
	{
		if (idx == start)
			break;
		s.push(idx);
		idx = itrack[idx];
	}

	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		printf("%c", ctrack[cur]);
	}
}

void Solution(int start, int goal)
{
	itrack[start] = 999999;
	q.push(start);
	int cur, d, s, l, r;
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur == goal) {
			Print(cur, start, itrack, ctrack);
			printf("\n");
			break;
		}
		d = D(cur);
		s = S(cur);
		l = L(cur);
		r = R(cur);
		if (itrack[d] == -1) {
			itrack[d] = cur;
			ctrack[d] = 'D';
			q.push(d);
		}
		if (itrack[s] == -1) {
			itrack[s] = cur;
			ctrack[s] = 'S';
			q.push(s);
		}
		if (itrack[l] == -1) {
			itrack[l] = cur;
			ctrack[l] = 'L';
			q.push(l);
		}
		if (itrack[r] == -1) {
			itrack[r] = cur;
			ctrack[r] = 'R';
			q.push(r);
		}
	}
}

int main()
{
	int TestCase;
	int start, goal;
	cin >> TestCase;
	for (int i = 0; i < TestCase; i++) {
		cin >> start >> goal;
		fill(itrack, itrack + MAX_LEN, -1);
		Solution(start, goal);
		fill(ctrack, ctrack + MAX_LEN, 0);
		queue<int> emptyQueue;
		swap(q, emptyQueue);
	}
	return 0;
}
