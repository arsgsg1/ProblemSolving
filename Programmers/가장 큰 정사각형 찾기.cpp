#include <vector>
#include <algorithm>
using namespace std;
int width, height;

int solution(vector<vector<int>> board)
{
	int answer = 0;
	int MaxSize = 0;
	//dp[W][H] = 오른쪽 하단 기준, 가장 큰 정사각형의 변의 길이
	height = board.size();
	width = board[0].size();
	if (height == 1 || width == 1)
		return 1;
	for (int i = 1; i < height; i++) {
		for (int j = 1; j < width; j++) {
			if (board[i][j] == 1) {
				board[i][j] = min(board[i - 1][j - 1],
					min(board[i][j - 1], board[i - 1][j])) + 1;
				MaxSize = max(MaxSize, board[i][j]);
			}
		}
	}
	answer = MaxSize * MaxSize;
	return answer;
}