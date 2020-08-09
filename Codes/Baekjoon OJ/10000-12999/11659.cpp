#include <iostream>
using namespace std;

const int MAX = 100000;

int arr[MAX], psum[MAX + 1];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		psum[i + 1] = psum[i] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;

		cout << psum[b + 1] - psum[a] << '\n';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: psum
���� ���		: psum�� Ȱ���ϸ� ���� ������ �ʴ� ������ ���� O(1)�ð��� ���� �� �ִ�.
������ ������		: 
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////