#include <iostream>
using namespace std;

int main() {
	int t, i, j, k, n, m; scanf("%d", &t);
	while (t-->0) {
		int d[30][30] = { 0 };
		scanf("%d %d", &n, &m);
		for (i = 0; i <= m; i++) d[1][i] = i;
		for (i = 2; i <= n; i++)
			for (j = i; j <= m; j++)
				for (k = j; k >= i; k--)
					d[i][j] += d[i - 1][k - 1];
		printf("%d\n", d[n][m]);
	}
	return 0;
}