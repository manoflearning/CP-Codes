#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct bb {
	int st;
	int en;
};

vector<bb> arr;

bool comp(bb a, bb b);

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int st, en;
		cin >> st >> en;

		arr.push_back({ st, en });
	}

	sort(arr.begin(), arr.end(), comp);

	int ans = 0;

	int end = 0;
	for (int i = 0; i < n; i++) {
		while (i < n && end > arr[i].st) i++;

		if (i < n) {
			end = arr[i].en;
			ans++;
		}
	}

	cout << ans;

	return 0;
}

bool comp(bb a, bb b) {
	if (a.en != b.en) return a.en < b.en;
	return a.st < b.st;
}
/*////////////////////////////////////////////////////////////////////
���� �ع�		: �׸��� �˰�����
���� ���		: ȸ�ǰ� ���� �����İ� �߿�. ������ ȸ�� �� ������ �ð��� ���� ���� ȸ�Ǹ� ������, ���� �κ� ������ ������.
������ ������		:
���� ����		: 1. while���� ������ ���� �� ����
				  2.
*/////////////////////////////////////////////////////////////////////