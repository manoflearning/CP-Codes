#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> dot;

bool compare(pair<int, int> a, pair<int, int> b);

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		dot.push_back(make_pair(x, y));
	}

	sort(dot.begin(), dot.end(), compare);

	for (int i = 0; i < n; i++)
		cout << dot[i].first << ' ' << dot[i].second << '\n';

	return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}
/*/////////////////////////////////////////////////////////////////////
���� �ع�		: 
���� ���		: 
������ ������		:
���� ����		: 1.
				  2.
*//////////////////////////////////////////////////////////////////////