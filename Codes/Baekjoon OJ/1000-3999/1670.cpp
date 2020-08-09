#include <iostream>
using namespace std;

const int MAX = 10000;

int n;
long long int dp[MAX + 1];

long long int handshake(int x);

int main() {
	scanf("%d", &n);

	printf("%lld", handshake(n));

	return 0;
}

long long int handshake(int x) {
	//memoization
	if (dp[x] != 0) return dp[x];
	//base case
	if (x == 0 || x == 2) return 1;
	//
	for (int i = 2; i <= x; i += 2) {
		dp[x] += handshake(i - 2) * handshake(x - i);
		dp[x] %= 987654321;
	}

	return dp[x];
}
/*
���� �ع�		: ���� ��ȹ�� (top down), ������ ����
���� ���		:
������ ������		:
���� ����		: 1.
				  2.
*/
///////////////////////////////////////////////////////////////////////
/*
#include <iostream>
using namespace std;

const int MAX = 10000;

int n;
long long int dp[MAX + 1];

int main() {
	scanf("%d", &n);

	dp[0] = 1, dp[2] = 1;
	for (int i = 4; i <= n; i += 2) {
		for (int l = 2; l <= i; l += 2) {
			dp[i] += dp[l - 2] * dp[i - l];
			dp[i] %= 987654321;
		}
	}

	printf("%lld", dp[n]);

	return 0;
}
*/
/*
���� �ع�		: ���� ��ȹ�� (bottom up), ������ ����
���� ���		:
������ ������		:
���� ����		: 1.
				  2.
*/
///////////////////////////////////////////////////////////////////////