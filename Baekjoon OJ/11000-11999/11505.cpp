#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int n, flag;
vector<long long> tree;

void update(int num, int value);
long long mul(int L, int R, int n, int nL, int nR);

int main() {
	int m, k;
	cin >> n >> m >> k;

	for (flag = 1; flag < n; flag *= 2);
	tree.resize(2 * flag, 1);
	
	for (int i = flag; i < flag + n; i++)
		cin >> tree[i];
	for (int i = flag - 1; i >= 1; i--)
		tree[i] = tree[2 * i] * tree[2 * i + 1] % MOD;
	//
	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) update(b, c);
		else cout << mul(b, c, 1, 1, flag) << '\n';
	}

	return 0;
}

void update(int num, int value) {
	int upd = (flag - 1) + num;
	tree[upd] = value;

	while (upd > 1) {
		upd /= 2;

		tree[upd] = tree[2 * upd] * tree[2 * upd + 1] % MOD;
	}
}
long long mul(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 1;
	if (L <= nL && nR <= R) return tree[n];

	int mid = (nL + nR) / 2;
	return mul(L, R, 2 * n, nL, mid) * mul(L, R, 2 * n + 1, mid + 1, nR) % MOD;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ����Ʈ��
���� ���		: ����Ʈ���� ������ ���� ������ �� �ִ�
������ ������		: 
���� ����		: 1. Ʈ���� �� ���� 1�� �ʱ�ȭ�� �ؾ���. �׷��� �ؾ� ���� ����� ������ ��ġ�� ����.
				  2. 
*/////////////////////////////////////////////////////////////////////