#include <string>
#include <sstream>
#include <iostream>
using namespace std;
int main()
{
	string str, buf;
	getline(cin, str);
	istringstream ss(str);
	int cnt = 0;
	while (getline(ss, buf, ' ')) {
		if (buf.size() == 0)
			continue;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}