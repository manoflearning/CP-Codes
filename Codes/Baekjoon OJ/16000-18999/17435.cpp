#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 200000;
//f[a][b]�� a���� 2^b�� �̵��ؼ� �����ϴ� ���
int f[MAX + 1][19];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m; cin >> m;
	
	for (int i = 1; i <= m; i++)
		cin >> f[i][0];

	for (int i = 1; i <= 18; i++) {
		for (int j = 1; j <= m; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
		}
	}

	int Q; cin >> Q;
	
	while (Q--) {
		int n, x;
		cin >> n >> x;

		for (int i = 18; i >= 0; i--) {
			if (n >= 1 << i) {
				n -= 1 << i;
				x = f[x][i];
			}
		}

		cout << x << '\n';
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ��� ���̺�
���� ���		:
������ ������		:
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////