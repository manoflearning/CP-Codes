#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	for (int test = 0; test < t; test++) {
		int n;
		scanf("%d", &n);

		int sum = 0;
		for (int i = 0; i < n; i++) {
			int sam;
			scanf("%d", &sam);

			sum += sam;
		}
		printf("%d\n", sum);
	}

	return 0;
}
/*
���� �ع�		: 
���� ���		:
������ ������		:
���� ����		: 1. 
				  2.
*/
//////////////////////////////////////////////////////////////////////