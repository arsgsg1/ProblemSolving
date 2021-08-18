#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MASK 0x3ffffff //��ü ���ĺ� ����ũ
int cur_mask = MASK; //ó�� �˰� �ִ� ���ĺ�
int N, M;
vector<int> v;
void convertAlpha2Bit()
{
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int word = 0;
		for (const auto& c : str) {
			word |= 1 << c - 'a'; //���ĺ��� ��Ʈ�� ��ȯ
		}
		v.push_back(word);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	convertAlpha2Bit();
	int op = 0; 
	char ch = 0;
	for (int i = 0; i < M; i++) {
		scanf("%d %c", &op, &ch);
		if (op == 1) { //<<, &�� Ư�� ��Ʈ �����
			cur_mask &= MASK - (1 << ch - 'a');
		}
		else {
			cur_mask |= 1 << ch - 'a';
		}
		int cnt = 0;
		for (const auto& word : v) {
			if ((cur_mask & word) == word) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}