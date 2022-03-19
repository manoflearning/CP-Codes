#include <iostream>
#define ll long long
using namespace std;

const int MAX = 1299709;

bool sosu[MAX + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	sosu[2] = true;
	for (int i = 3; i <= MAX; i += 2)
		sosu[i] = true;
	for (ll i = 3; i <= MAX; i += 2) {
		if (!sosu[i]) continue;
		for (ll l = i * i; l <= MAX; l += 2 * i)
			sosu[l] = false;
	}

	int T;
	cin >> T;

	while (T--) {
		int x;
		cin >> x;

		if (sosu[x]) cout << 0 << '\n';
		else {
			int left = x, right = x;
			while (!sosu[left]) left--;
			while (!sosu[right]) right++;
			left++, right--;
			
			cout << right - left + 2 << '\n';
		}
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �����佺�׳׽��� ü 
���� ���		:
������ ������		:
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////