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
			//���� : ��� ���ڿ��� ���̰� ���� ���ڿ��� ���̺��� �۴ٸ� �н�
			if (idx - bombLen < 0)
				continue;
			bool boom = true;
			//���� ���ڿ��� ������ ���ڵ�� ��
			for (int j = 0; j < bombLen; j++) {
				if (result[idx - j - 1] != bomb[bombLen - j - 1]) {
					boom = false;
					break;
				}
			}
			//���� ���ڿ��� ��� ��ġ�ϴ� ���
			if (boom) {
				idx -= bombLen;
			}
		}
	}
	if (!idx) {
		printf("FRULA\n");
	}
	else {
		//����� �ε�����ŭ ���
		for(int i = 0; i<idx; i++)
		printf("%c", result[i]);
	}
	return 0;
}