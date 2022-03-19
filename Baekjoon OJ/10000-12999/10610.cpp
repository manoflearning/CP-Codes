#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(char a, char b);

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string N; cin >> N;

	sort(N.begin(), N.end(), cmp);

	if (N.back() != '0') {
		cout << -1;
		return 0;
	}

	int sum = 0;
	for (char x : N)
		sum += x - '0';

	if (sum % 3 != 0) {
		cout << -1;
		return 0;
	}

	cout << N;

	return 0;
}

bool cmp(char a, char b) {
	return a > b;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: ����
������ ������		: 1�� �ڸ��� 0�̰�, �� �ڸ����� ���� 3�� ������, 3�� ����̴�. �׷��� �ʴٸ� 3�� ����� �ƴϴ�.
�ð����⵵		: O(nlgn)
���� ����		: 1. 
				  2.
*/////////////////////////////////////////////////////////////////////