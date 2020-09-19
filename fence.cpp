#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

int findmax(vector<int>& h, int left, int right) {
	if (left == right) {
		return h[left];
	}

	int mid = (left + right) / 2;
	
	int ret = max(findmax(h, left, mid), findmax(h, mid+1, right));

	
	int low = mid;
	int high = mid + 1;
	int height = min(h[low], h[high]);

	ret = max(ret, 2 * height);

	while (left < low || high < right) {
		if (high < right && (low == left || h[low - 1] < h[high + 1])) {
			high++;
			height = min(height, h[high]);
		}
		else {
			low--;
			height = min(height, h[low]);
		}

		ret = max(ret, height * (high - low + 1));
	}
	return ret;
}

int main(){
	int tc,n;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> n;
		vector<int> h(n, 0);

		for (int j = 0; j < n; j++) {
			cin >> h[j];
		}

		cout << findmax(h, 0, n - 1) << endl;
	}
}