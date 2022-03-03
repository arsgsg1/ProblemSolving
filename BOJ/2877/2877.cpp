#include <iostream>
#include <vector>
using namespace std;
int N;
int main()
{
	cin >> N;
	int num = ++N;
	vector<int> bin;
	while (num != 0) {
		if (num % 2 == 0) 
			bin.push_back(0);
		else
			bin.push_back(1);
		num /= 2;
	}
	for (int i = bin.size() - 2; i >= 0; i--) {
		if (bin[i] == 0)
			printf("%d", 4);
		else
			printf("%d", 7);
	}
	return 0;
}