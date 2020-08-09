#include <iostream>
#include <stack>
using namespace std;

int tower[500000];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &tower[i]);

	stack<int> tallTower;
	for (int i = 0; i < n; i++) {
		while (true) {
			if (tallTower.empty()) {
				printf("0 ");
				tallTower.push(i);
				break;
			}
			else if (tower[tallTower.top()] < tower[i]) tallTower.pop();
			else {
				printf("%d ", tallTower.top() + 1);
				tallTower.push(i);
				break;
			}
		}
	}

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: ������ Ȱ��. ������׷��� ������ Ȱ���� Ǯ�̿� ����� ���� ���. ���� ������ ž�� �� ����� ž���� ���ų� ũ�ٸ� ���, �۴ٸ� pop����.
���� ���		: 
������ ������		: 
���� ����		: 1. 
				  2. 
*///////////////////////////////////////////////////////////////////////