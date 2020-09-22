#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int board[100][100], n, cashe[100][100];

int findroute(int y, int x) {
	int current = board[y][x];

	int& ret = cashe[y][x];

	if (y >= n || x >= n)
		return 0;

	if (y == n-1 && x == n-1)
		return 1;

	if (ret != -1) return ret;

	return ret=(findroute(y + current, x) || findroute(y, x + current));
}

int main() {
	int tc;
	scanf("%d", &tc);

	if (tc < 0 || tc >50)
		exit(-1);

	for (int i = 0; i < tc; i++) {
		
		scanf("%d", &n);

		if (n < 2 || n>100)
			exit(-1);


		memset(cashe, -1, sizeof(cashe));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				scanf("%d", &board[j][k]);
			}
		}

		if (findroute(0, 0) == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}

}