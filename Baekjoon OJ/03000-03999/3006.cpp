#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

int flag;
int whereNum[MAX + 1];
vector<int> sgtr;

int sum(int L, int R, int n, int nL, int nR);
void update(int num);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//
	int n;
	cin >> n;

	for (flag = 1; flag < n; flag *= 2);
	sgtr.resize(2 * flag, 0);
	//construct
	for (int i = flag; i < flag + n; i++)
		sgtr[i] = 1;
	for (int i = flag - 1; i >= 1; i--)
		sgtr[i] = sgtr[2 * i] + sgtr[2 * i + 1];
	//1~n������ ���� ��ġ�� ����
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;

		whereNum[x] = i;
	}
	//
	int start = 1, end = n;

	while (true) {
		cout << sum(1, whereNum[start] - 1, 1, 1, flag) << '\n';
		update(whereNum[start]);
		start++;

		if (start > end) break;

		cout << sum(whereNum[end] + 1, n, 1, 1, flag) << '\n';
		update(whereNum[end]);
		end--;
		
		if (start > end) break;
	}

	return 0;
}

int sum(int L, int R, int n, int nL, int nR) {
	if (R < nL || nR < L) return 0;
	if (L <= nL && nR <= R) return sgtr[n];

	int mid = (nL + nR) / 2;
	return sum(L, R, 2 * n, nL, mid) + sum(L, R, 2 * n + 1, mid + 1, nR);
}
void update(int num) {
	int upd = (flag - 1) + num;
	sgtr[upd] = 0;

	while (upd > 1) {
		upd /= 2;

		sgtr[upd] = sgtr[2 * upd] + sgtr[2 * upd + 1];
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ���׸�Ʈ Ʈ��
���� ���		: ������ �ϴ� ������ �����ϴ� ������ ������ �����ϴ� ���׸�Ʈ Ʈ��.
������ ������		: 
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////