#include <iostream>
#define ll long long
using namespace std;

ll f[(int)1e7];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	ll sum = 1;
	f[1] = 1;

	for (ll i = 2; ; i++) {
		f[i] = 1 + f[i - f[f[i - 1]]];

		sum += f[i];
		
		if (sum >= n) {
			cout << i;
			break;
		}
	}

	return 0;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ��� ����
������ ������		: x > 1�� ��, ��ȭ���� f(n) = 1 + f(n - f(f(n - 1))) (��ó: https://stackoverflow.com/questions/12786087/golombs-sequence)
�ð����⵵		: �� �� ����
���� ����		: 1. 
				  2. 
*/////////////////////////////////////////////////////////////////////