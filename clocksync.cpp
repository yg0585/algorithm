#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

vector<vector<int> > button({
    vector<int>({ 0, 1, 2 }),
    vector<int>({ 3, 7, 9, 11 }),
    vector<int>({ 4, 10, 14, 15 }),
    vector<int>({ 0, 4, 5, 6, 7 }),
    vector<int>({ 6, 7, 8, 10, 12 }),
    vector<int>({ 0, 2, 14, 15 }),
    vector<int>({ 3, 14, 15 }),
    vector<int>({ 4, 5, 7, 14, 15 }),
    vector<int>({ 1, 2, 3, 4, 5 }),
    vector<int>({ 3, 4, 5, 9, 13 })
    });

int INF = 9999;

bool isclock(vector<int>& clock) {
    for (int i = 0; i < 16; i++) {
        if (clock[i] != 12)
            return false;
    }

    return true;
}

void pushbutton(vector<int>&clock, int i) {
    int size = button[i].size();

    for (int j = 0; j < size; j++) {
        int clocbut = button[i][j];
        clock[clocbut] += 3;

        if (clock[clocbut] == 15)
             clock[clocbut] = 3;
    }
}

int minbutton(vector<int>& clock, int currentswitch) {
    if (currentswitch == 10) return isclock(clock) ? 0 : INF;
       
    int ret = INF;

    for (int i = 0; i < 4; i++) {
        ret = min(ret, i + minbutton(clock, currentswitch + 1));
        pushbutton(clock, currentswitch);
    }

    return ret;
}

int main() {
	int tc;
    vector <int> clock(16);

	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
        for (int j = 0; j < 16; j++)           
            cin >> clock[j];

        int result = minbutton(clock,0);

        if (result == 9999) {
            cout << -1 << endl;
        }
        else {
            cout << result << endl;
        }
	}
}