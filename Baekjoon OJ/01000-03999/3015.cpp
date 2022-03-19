#include <iostream>
#include <stack>
using namespace std;

const int MAX = 500000;

int height[MAX];
int Count[MAX];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &height[i]);

	for (int i = 0; i < n; i++)
		Count[i] = 1;

	stack<int> people;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int clone = 1;

		while (!people.empty() && height[i] >= height[people.top()]) {
			ans += Count[people.top()];
			if (height[i] == height[people.top()]) clone += Count[people.top()];
			people.pop();
		}

		if (!people.empty() && height[i] < height[people.top()]) ans++;

		people.push(i);
		Count[i] = clone;
	}

	printf("%lld", ans);

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ������ Ȱ��. ���� Ű���� ���� Ű�� ���ÿ��� ����, ���ų� ū Ű�� ����. �̶� ���� Ű ó���� �߿�(�ϴ� ���ÿ��� �� ��, �ٽ� ����).
���� ���		:
������ ������		:
���� ����		: 1. ���� Ű�� ���� Ű�� ó������ ����.
				  2. ���� for���� �������� ���� ��
				  3. �־��� ��� O(n^2)�� �ð����⵵(���� Ű)
*///////////////////////////////////////////////////////////////////////