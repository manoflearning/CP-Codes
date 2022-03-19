#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		pq.push(x);
	}

	int ans = 0;

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		ans += a + b;

		pq.push(a + b);
	}

	cout << ans;

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �켱���� ť
���� ���		: �ð����⵵ O(n * lgn)
������ ������		: 
���� ����		: 1. �޸� �ʰ�
				  2. 
*/////////////////////////////////////////////////////////////////////