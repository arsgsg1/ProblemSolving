#include <iostream>
#include <set>
#include <string>
using namespace std;
#define CONST 10000
set<int> s;
bool IsSelf(int num)
{
	int sum = num;
	string str = to_string(num);
	for (const auto& c : str)
		sum += c - '0';
	s.insert(sum);
	if (s.find(num) == s.end())
		return true;
	else
		return false;
}
int main()
{
	for (int i = 1; i <= CONST; i++) {
		if (IsSelf(i))
			printf("%d\n", i);
	}
	return 0;
}