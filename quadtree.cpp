#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <string.h>
#pragma warning(disable:4996)

using namespace std;

int position;

string reverse(string::iterator &it) {
	char head = *it;
	++it;

	if (head != 'x') {
		return string(1, head);
	}

	string upperleft = reverse(it);
	string upperright = reverse(it);
	string lowerleft = reverse(it);
	string lowerright = reverse(it);

	return string("x") + lowerleft + lowerright + upperleft + upperright;

}

int main(){
	int tc;
	string quadtree;

	cin >> tc;

	for (int i = 0; i < tc; i++) {
		cin >> quadtree;
		position = 0;
	
		string::iterator it = quadtree.begin();

		cout << reverse(it) << endl;
	}
}