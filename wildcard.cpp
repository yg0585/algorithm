#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

int n;

int cache[101][100];

string W, S;

bool matchMemorized(int w, int s){
	int& ret = cache[w][s];
	if (ret != -1) return ret;
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
		return ret = matchMemorized(w + 1, s + 1);

	if (w == W.size()) return ret = (s == S.size());

	if(W[w] == '*')
		if(matchMemorized(w+1,s) || (s<S.size()&& matchMemorized(w,s+1)))
			return ret = 1;

	return ret = 0;
}

int main() {
	int tc;
	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
		cin >> W;
		int n;
		cin >> n;
		vector<string> word;

		for (int j = 0; j < n; j++) {
			memset(cache, -1, sizeof(cache));
			cin >> S;
			if (matchMemorized(0, 0) == 1)
				word.push_back(S);
		}
		sort(word.begin(), word.end());
		for (int j = 0; j < word.size(); j++)
			cout << word[j] << endl;
	}
}