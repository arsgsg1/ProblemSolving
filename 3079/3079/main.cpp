#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
long long MaxTime = 0;
bool Possible(const vector<int>& time, long long target)
{
	long long total = 0;
	//제한 시간 내에 각 입국심사대가 처리할 수 있는 최대 인원 수 계산
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
	//이분탐색을 위한 나올 수 있는 최대 시간을 설정
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