#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	int count = 0;
	for (int i = 5; i <= n; i+=5) {
		int sam = i;
		while (sam % 5 == 0) {
			sam /= 5;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}

/*
���� �ع�		: ���� (���μ�����)
���� ���		:
������ ������	:
���� ����		: 1.
				  2.
*/