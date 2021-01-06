#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 1000000
char result[MAX_SIZE];
int main()
{
	string str, bomb;
	cin >> str >> bomb;
	int len = str.size(), idx = 0;
	int bombLen = bomb.size();
	for (int i = 0; i < len; i++) {
		result[idx++] = str[i];
		if (result[idx - 1] == bomb[bombLen - 1]) {
			//예외 : 결과 문자열의 길이가 폭발 문자열의 길이보다 작다면 패스
			if (idx - bombLen < 0)
				continue;
			bool boom = true;
			//폭발 문자열의 나머지 문자들과 비교
			for (int j = 0; j < bombLen; j++) {
				if (result[idx - j - 1] != bomb[bombLen - j - 1]) {
					boom = false;
					break;
				}
			}
			//폭발 문자열과 모두 일치하는 경우
			if (boom) {
				idx -= bombLen;
			}
		}
	}
	if (!idx) {
		printf("FRULA\n");
	}
	else {
		//계산한 인덱스만큼 출력
		for(int i = 0; i<idx; i++)
		printf("%c", result[i]);
	}
	return 0;
}