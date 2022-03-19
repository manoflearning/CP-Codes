#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[(int)1e5];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int L = 0;
	ll ans = 1e12;
	for (int i = 1; i < n; i++) {
		while (arr[i] - arr[L] >= m && L < i) {
			ans = min(ans, arr[i] - arr[L]);
			L++;
		}
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �� ������ ����
������ ������		: 
�ð����⵵		: O(n)
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////