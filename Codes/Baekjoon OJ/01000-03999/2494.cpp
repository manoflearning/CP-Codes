#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000;

int n;
string now, want;
int dp[MAX + 1][10];

int find_min(int x, int flag);
int trans(int flag);
void find_path(int x, int flag);

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	memset(dp, -1, sizeof(dp));

	cin >> n >> now >> want;

	cout << find_min(0, 0) << '\n';

	find_path(0, 0);

	return 0;
}

int find_min(int x, int flag) {
	flag = trans(flag);
	int& ret = dp[x][flag];
	//memoization
	if (ret != -1) return ret;
	//base case
	if (x == n) return ret = 0;

	int gap = trans(want[x] - (now[x] + flag)), plus = 9 * MAX + 1;

	if (gap == 0) plus = find_min(x + 1, flag);
	else {
		plus = min(plus, find_min(x + 1, flag + gap) + gap);
		plus = min(plus, find_min(x + 1, flag) + (10 - gap));
	}
	
	return ret = plus;
}
int trans(int flag) {
	return (flag + 100) % 10;
}
void find_path(int x, int flag) {
	//base case
	if (x == n) return;

	flag = trans(flag);
	
	int gap = trans(want[x] - (now[x] + flag));
	if (gap == 0) {
		//cout << x + 1 << ' ' << 0 << '\n';
		find_path(x + 1, flag);
	}
	else {
		if (dp[x + 1][trans(flag + gap)] + gap == dp[x][flag]) {
			cout << x + 1 << ' ' << gap << '\n';
			find_path(x + 1, flag + gap);
		}
		else {
			cout << x + 1 << ' ' << -(10 - gap) << '\n';
			find_path(x + 1, flag);
		}
	}
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: dp
���� ���		: dp ������
������ ������		: 
���� ����		: 1. -1�� �ʱ�ȭ�� dp �迭�� �ݵ�� 0���� ����� �Լ��� ������ ��.
				  2. ȸ�� Ƚ���� 0�� ��� ������� ���ƾ� ��.
				  3. ������ dp�� ������ �ȵ�
*/////////////////////////////////////////////////////////////////////