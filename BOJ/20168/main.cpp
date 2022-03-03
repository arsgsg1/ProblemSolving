#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 160001
int dp[MAX_SIZE];
bool solution(vector<int> nums, int k)
{
	int sum = 0;
	for(int i = 0; i < nums.size(); i++){
		sum = nums[i];
		dp[sum]++;
		for (int j = i + 1; j < nums.size(); j++) {
			sum += nums[j];
			dp[sum]++;
		}
	}
	return dp[sum] == k;
}
void main()
{
	//solution({ 4,3,2,3,5,2,1 }, 4);
	solution({ 1, 2, 3, 4 }, 2);
}