#include <iostream>
#include <string>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	//�ʿ��� ���ڼ���ŭ �ݺ��ϱ�
	for (int j = 0, index = -1; j < number.length() - k; j++) {
		char max = 0;
		//�տ��� ���ܾ� �Ǵ� ���� �߿� ���� ū�� üũ
		for (int i = index + 1; i <= k + j; i++) {
			if (max < number[i]) {
				index = i;
				max = number[i];
			}
		}
		//���� ū���� ���信 �߰�
		answer += max;
	}
	return answer;
}