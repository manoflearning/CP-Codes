#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int x; cin >> x;
		arr.push_back(x);
	}

	sort(arr.begin(), arr.end());

	for (int x : arr)
		cout << x << ' ';

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ����
������ ������		: 
�ð����⵵		: O(nlgn)
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////