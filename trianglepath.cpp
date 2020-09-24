#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

int triangle[100][100];

int cache[100][100];

int n;

int maxpath(int y , int x) {
	
	int current = triangle[y][x];

	if (y == n - 1)
		return current;

	int& ret = cache[y][x];

	if (ret != 0) return ret;

	return ret += max(current + maxpath(y + 1, x), current + maxpath(y + 1, x + 1));
}

int main() {
	int tc;
	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
		
		cin >> n;

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < j + 1; k++) {
				scanf("%d", &triangle[j][k]);
			}
		}
		memset(cache, 0, sizeof(cache));
		cout <<	maxpath(0,0) << endl;
	}
}