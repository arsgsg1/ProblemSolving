#include <iostream>
#include <vector>
using namespace std;
int A, B, V;
bool Possible(unsigned int day)
{
	unsigned int height = (day - 1) * (A - B) + A;
	if (height >= V)
		return true;
	else
		return false;
}
void BinSearch()
{
	unsigned int left = 1;
	unsigned int right = 1000000000;
	unsigned int mid = (left + right) / 2;
	while (left <= right) {
		if (Possible(mid))
			right = mid - 1;
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	printf("%d\n", mid + 1);
}
int main()
{
	scanf("%d %d %d", &A, &B, &V);
	if (A >= V) {
		printf("1\n");
		return 0;
	}
	BinSearch();
	return 0;
}