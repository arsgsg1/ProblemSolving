#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	string sub;
	int len = phone_book.size();
	for (int i = 0; i<len; i++) {
		for (int j = 0; j<len; j++) {
			if (i == j)
				continue;
			sub = phone_book[j].substr(0, phone_book[i].length());
			if (sub == phone_book[i])
				return false;
		}
	}
	return answer;
}