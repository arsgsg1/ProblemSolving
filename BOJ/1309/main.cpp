#include <iostream>
using namespace std;
#define CONST 9901
int N;
int arr[100001][3];
/*
1. ���ڰ� N��° �ٿ� �ִ� ���
	1.1 �����ʿ� �ִ� ���
	1.2 ���ʿ� �ִ� ���
2. ���ڰ� N��° �ٿ� ���� ���
*/
int main()
{
	cin >> N;
	arr[1][0] = 1;
	arr[1][1] = 1;
	arr[1][2] = 1;
	for (int i = 2; i <= N; i++) {
		arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % CONST;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % CONST;
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % CONST;
	}
	int answer = (arr[N][0] + arr[N][1] + arr[N][2]) % CONST;
	printf("%d\n", answer);
	return 0;
}