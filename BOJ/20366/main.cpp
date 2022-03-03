/*
����Ž�� : 600C4�� ����� ���� �ð��ʰ�
�� ���� �����̷� ������� ����� ��� -> ���� ����
2���� ��� (������ �ٽ�)
1. �ϳ��� ������� ����� ��츦 ��� ���ϰ�, ������ �� �ε����� ��ġ�� �����鼭, �ٷ� ���� ���� �� (���̰� ���� �۱� ����)
2. �����̸� ���� ���� 3ĭ�� padding�� �ΰ�, ���� ���� + �������ͷ� �ּڰ� Ž��
*/
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX_SIZE 600
int N, answer = 2e9 + 1;
int arr[MAX_SIZE];
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	int elsa, anna;
	for (int i = 0; i < N - 3; i++) {
		for (int j = i + 3; j < N; j++) {
			anna = arr[i] + arr[j];
			int s = i + 1, e = j - 1;
			while (s < e) {
				elsa = arr[s] + arr[e];
				int result = anna - elsa;
				answer = min(abs(result), answer);
				if (result > 0)
					s++;
				else
					e--;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}