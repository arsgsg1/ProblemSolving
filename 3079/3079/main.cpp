#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
long long MaxTime = 0;
bool Possible(const vector<int>& time, long long target)
{
	long long total = 0;
	//���� �ð� ���� �� �Ա��ɻ�밡 ó���� �� �ִ� �ִ� �ο� �� ���
	for (const auto& t : time)
		total += target / t;

	if (total >= M)
		return true;
	else
		return false;
}
void BinSearch(const vector<int>& time)
{
	long long left = 1;
	//�̺�Ž���� ���� ���� �� �ִ� �ִ� �ð��� ����
	long long right = MaxTime * M;
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (Possible(time, mid)) 
			right = mid - 1;
		else 
			left = mid + 1;
	}
	printf("%lld\n", left);
}
int main()
{
	scanf("%d %d", &N, &M);
	vector<int> time(N, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &time[i]);
		if (MaxTime < time[i])
			MaxTime = time[i];
	}
	BinSearch(time);
	return 0;
}