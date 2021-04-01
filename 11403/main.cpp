#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 101
int N;
int arr[MAX_SIZE][MAX_SIZE];
void floyd()
{
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) {
					arr[i][j] = 1;
				}
			}
		}
	}
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	floyd();
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}