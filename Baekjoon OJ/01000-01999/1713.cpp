#include <iostream>
using namespace std;

const int MAX = 100;

int pic[MAX + 1], history[MAX + 1];
bool recommand[MAX + 1];
int Count;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int sam;
		cin >> sam;

		if (!recommand[sam]) {
			if (Count == n) {
				int min = 1001, flag;
				for (int l = 1; l <= MAX; l++) {
					if (recommand[l]) {
						if (pic[l] == min && history[l] < history[flag]) flag = l;
						else if (pic[l] < min) min = pic[l], flag = l;
					}
				}

				pic[flag] = 0, recommand[flag] = false;
				Count--;
			}

			history[sam] = i;

			pic[sam]++, recommand[sam] = true;
			Count++;
		}
		else pic[sam]++;
	}

	for (int i = 1; i <= MAX; i++)
		if (recommand[i]) cout << i << ' ';

	return 0;
}
/*//////////////////////////////////////////////////////////////////////
���� �ع�		: �迭�� Ȱ��, ����
���� ���		: 
������ ������		: 
���� ����		: 1. ��õ ���� Ƚ���� ���� ���� �л��� �� �� �̻��� ��츦 �������� ����
				  2. 
*///////////////////////////////////////////////////////////////////////